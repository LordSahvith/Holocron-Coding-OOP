class vector
{
    int sz;
    double* element;

  public:
    vector(int s);

    int size() const
    {
        return sz;
    }
};

int main()
{
    vector age(4);
    age[0] = 1.0;
}