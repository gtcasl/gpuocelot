
__kernel void hello(__global char *input, __global char *output)
{
  int id = get_global_id(0);
  output[id] = input[id]+1;
}


