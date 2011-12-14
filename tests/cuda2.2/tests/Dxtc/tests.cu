
// Work in progress:

// Odd/Even sort.
__device__ void sortColors3(float * v, float3 * colors, int * xrefs)
{
	int tid = threadIdx.x;

	xrefs[tid] = tid;

	float e;
	const bool active = (tid != 0) && (tid != 15);
	
	for (int i = 0; i < 8; i++)
	{
		if (tid & 1) e = min(v[tid], v[tid+1]);
		else e = max(v[tid-1], v[tid]);
		v[tid] = e;

		if (active)
		{
			if (tid & 1) e = max(v[tid-1], v[tid]);
			else e = min(v[tid], v[tid+1]);
			v[tid] = e;
		}
	}
	
	/*for (int i = 0; i < 8; i++)
	{
		int x;
		{
			int odd = tid & 1;
			int x0 = xrefs[tid ^ odd];
			int x1 = xrefs[tid ^ !odd];
			int cmp = v[x0] > v[x1];
			if (cmp ^ odd) x = x0;
			else x = x0;
			xrefs[tid] = x;
		}
		
		if (active)
		{
			if (tid & 1) e = max(v[xrefs[tid-1]], v[xrefs[tid]]);
			else e = min(v[xrefs[tid]], v[xrefs[tid+1]]);
			v[xrefs[tid]] = e;
		}
	}*/
	
//	float3 tmp = colors[tid];
//	colors[cmp[tid]] = tmp;
}
