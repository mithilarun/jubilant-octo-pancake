
#define ROTR(a,b) (((a) >> (b)) | ((a) << (32-(b))))  //Rotate Right
#define SHR(a,b) ((a) >> (b))                         //Shift Right
#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define EPSILON0(x) (ROTR(x,2) ^ ROTR(x,13) ^ ROTR(x,22))
#define EPSILON1(x) (ROTR(x,6) ^ ROTR(x,11) ^ ROTR(x,25))
#define SIGMA0(x) (ROTR(x,7) ^ ROTR(x,18) ^ SHR(x,3))
#define SIGMA1(x) (ROTR(x,17) ^ ROTR(x,19) ^ SHR(x,10))
