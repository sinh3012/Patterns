class Singleton
{
public:
  static Singleton& Instance()
    {
      static Singleton s;
      return s;
    }
private:
  Singleton() {} 
  ~Singleton() {}
  Singleton(Singleton const&) = delete;
  Singleton& operator= (Singleton const&) = delete;
};
