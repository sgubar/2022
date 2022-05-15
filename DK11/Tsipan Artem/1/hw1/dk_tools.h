void mat_sub(double* a, double* b, double* c, int width, int height)
{
    for(int i = 0; i < width * height; i++)
    {
        *(c + i) = *(a + i) - *(b + i);
    }
}
