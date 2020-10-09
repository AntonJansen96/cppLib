size_t countDigitOccurance(size_t n, size_t d)
{
    size_t count = 0;
    while (n)
    {
        if (n % 10 == d)
            ++count;

        n /= 10;
    }
    return count;
}
