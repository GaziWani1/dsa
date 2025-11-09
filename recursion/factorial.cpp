
int fact(int a)
{
    if (a <= 1)
    {
        return a;
    }
    int temp = a - 1;
    return a * fact(temp);
}

int main()
{
    int factValue = fact(5);
    cout << factValue << endl;
    return 0;
}