#include <iostream>
using namespace std;

inline int max2(int a, int b)
{
  return (a > b) ? a : b;
}

inline int max4(int a, int b, int c, int d)
{
  int maxl = (a > b) ? a : b;
  int maxr = (c > d) ? c : d;

  return (maxl > maxr) ? maxl : maxr;
}

int s(char a, char b, int match_score, int mismatch_score)
{
  if (a == b)
  {
    return match_score;
  }
  
  return mismatch_score;
}

struct aligned_t
{
  char s;
  char t;
  int score;
};
typedef struct aligned_t aligned_t;



void align(const string & S, 
           const string & T,
           int match_score,
           int mismatch_score,
           int gap_open,
           int gap_extension)
{
  int m = S.length()-1;
  int n = T.length()-1;

  int E[m+2][n+2];
  int F[m+2][n+2];
  int G[m+2][n+2];
  int V[m+2][n+2];


  // initialize matrices
  for (int i = 0; i <= m; i++)
  {
    //E[i][0] = -gap_open + -gap_extension*i;
    E[i][0] = 0;
    F[i][0] = 0;
    G[i][0] = 0;
    V[i][0] = E[i][0];
  }

  for (int j = 0; j <= n; j++)
  {
    //F[0][j] = -gap_open + -gap_extension*j;
    F[0][j] = 0;
    E[0][j] = 0;
    G[0][j] = 0;
    V[0][j] = F[0][j];
  }

  G[0][0] = 0;
  V[0][0] = 0;

  int maxi = 0;
  int maxj = 0;
  int maxv = 0;

  // compute the matrix
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      E[i][j] = max2(E[i-1][j] - gap_extension,
                     V[i-1][j] - gap_open - gap_extension);

      F[i][j] = max2(F[i-1][j] - gap_extension,
                     V[i-1][j] - gap_open - gap_extension);

      G[i][j] = V[i-1][j-1] + s(S[i], T[j], match_score, mismatch_score);

      V[i][j] = max4(E[i][j], F[i][j], G[i][j], 0);

      if (V[i][j] > maxv)
      {
        maxv = V[i][j];
        maxi = i;
        maxj = j;
      }
    }
  }


  // // print the scores
  // cout << "V" << endl;
  // cout << "=======================================" << endl;
  // for (int i = 0; i <= m; i++)
  // {
  //   if (i == 0)
  //   {
  //     cout << " \t";
  //     for (int j = 0; j <= n; j++) { cout << T[j] << "\t"; }
  //     cout << endl;
  //   }
  // 
  //   cout << S[i] << "\t";
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << V[i][j];
  //     if (V[i][j] == maxv) { cout << "*"; }
  //     cout << "\t";
  //   }
  // 
  // 
  //   cout << endl;
  // }
  // 
  // cout << endl << endl;
  // cout << "E" << endl;
  // cout << "=======================================" << endl;
  // for (int i = 0; i <= m; i++)
  // {
  //   if (i == 0)
  //   {
  //     cout << " \t";
  //     for (int j = 0; j <= n; j++) { cout << T[j] << "\t"; }
  //     cout << endl;
  //   }
  // 
  //   cout << S[i] << "\t";
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << E[i][j];
  //     cout << "\t";
  //   }
  // 
  //   cout << endl;
  // }
  // 
  // cout << endl << endl;
  // cout << "F" << endl;
  // cout << "=======================================" << endl;
  // for (int i = 0; i <= m; i++)
  // {
  //   if (i == 0)
  //   {
  //     cout << " \t";
  //     for (int j = 0; j <= n; j++) { cout << T[j] << "\t"; }
  //     cout << endl;
  //   }
  // 
  //   cout << S[i] << "\t";
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << F[i][j];
  //     cout << "\t";
  //   }
  // 
  //   cout << endl;
  // }
  // 
  // cout << endl << endl;
  // cout << "G" << endl;
  // cout << "=======================================" << endl;
  // for (int i = 0; i <= m; i++)
  // {
  //   if (i == 0)
  //   {
  //     cout << " \t";
  //     for (int j = 0; j <= n; j++) { cout << T[j] << "\t"; }
  //     cout << endl;
  //   }
  // 
  //   cout << S[i] << "\t";
  //   for (int j = 0; j <= n; j++)
  //   {
  //     cout << G[i][j];
  //     cout << "\t";
  //   }
  // 
  //   cout << endl;
  // }
  // 
  // 
  // cout << "max score[" << maxi << "," << maxj << "]:" << maxv << endl;


  // print the alignment
  aligned_t trace[m+n];
  //int i = m; int j = n;
  int i = maxi, j = maxj;
  int tlen = 0;

  while (i > 0 && j > 0)
  {
    int v = V[i][j];
    trace[tlen].score = v;

    if (v == G[i][j])
    {
      trace[tlen].s = S[i];
      trace[tlen].t = T[j];
      i--;
      j--;
    }
    else if (v == E[i][j])
    {
      trace[tlen].s = S[i];
      trace[tlen].t = '-';
      i--;
    }
    else if (v == F[i][j])
    {
      trace[tlen].s = '-';
      trace[tlen].t = T[j];
      j--;
    }
    else // v == 0;
    {
      break;
    }

    tlen++;
  }

  // for (int k = tlen - 1; k >= 0; k--)
  // {
  //   cout << "   " << trace[k].s;
  // }
  // cout << endl;
  // 
  // for (int k = tlen - 1; k >= 0; k--)
  // {
  //   cout << "   " << trace[k].t;
  // }
  // cout << endl;
  // 
  // for (int k = tlen - 1; k >= 0; k--)
  // {
  //   printf(" %3d", trace[k].score);
  // }
  // cout << endl;
}


// int main(int argc, char ** argv)
// {
//   string S = "sMIKESCHATZ";
//   string T = "sQMILKSHAKE";
//   //string S = "sAATTTGGTG";
//   //string T = "sAAGGTCCA";
//   
//   int match_score = 10;
//   int mismatch_score = -2;
//   int gap_open = 4;
//   int gap_extension = 1;
// 
//   cout << "S: " << S << " " << S.length()-1 << endl;
//   cout << "T: " << T << " " << T.length()-1 << endl;
// 
//   align(S,T, match_score, mismatch_score, gap_open, gap_extension);
// 
//   return 0;
// }


