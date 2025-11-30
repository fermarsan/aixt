long map(long x, long eMin, long eMax, long sMin, long sMax);

long map(long x, long eMin, long eMax, long sMin, long sMax)
{
  return(x -eMin)*(sMax-sMin)/(eMax-eMin)+sMin;
}