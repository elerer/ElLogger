std::map<size_t,char*> MSGS =
{
  std::make_pair<size_t,char*>(1,"read less");
}

class ElLogger
{
public:

  void Logger()
  {
    size_t msg = 0;

    while(_loop)
    {
      _wrote = false;
      _AudioProxyQ.pop(&msg,1);
      write(msg);
      if(!wrote)
      {
        sleep(1s);
      }
    }

  }
  void write()
  {
    if(msg != 0)
    {
      std::cout << MSGS[msg] << '\n';
      msg = 0;
      _wrote = true;
    }
  }

  static ElLogger* GET_LOGGER()
  {

  }
  boost::lockfree::spsc_queue<size_t, boost::lockfree::capacity<4096> > _AudioProxyQ;
  std::atomic<bool> _loop;
  bool _wrote = false;
private:
  static ElLogger* _LOGGER;
  ElLogger()
  {}
};
