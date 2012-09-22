
//namespace Arboles{

    //Retorna el input pasado a mayúsculas.
    //Idea sacada de: http://www.dreamincode.net/forums/topic/15095-convert-string-to-uppercase-in-c/
    string strtoupper(string s)
    {
    string tmp=s;
    std::string::iterator i = tmp.begin();
    std::string::iterator end = tmp.end();
    
    while (i != end) {
      *i = std::toupper((unsigned char)*i);
     ++i;}
    
    return tmp;
    }
//}
