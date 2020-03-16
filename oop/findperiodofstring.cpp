#include "findperiodofstring.h"
#include <string>

FindPeriodOfString::FindPeriodOfString()
{

}

string FindPeriodOfString::solve(string s) {
    char c = s[0];
        string::size_type t, halfsize = s.size()/2+1;
        string s1;
        bool isPeriod;

        t = s.find(c, 1);

        while(t<halfsize)
        {
            s1 = s.substr(0, t);

            if(s.size()%t==0)
            {
                isPeriod = true;
                for(string::size_type i = t; i < s.size(); i+=t)
                {
                    if(s1!=s.substr(i,t))
                    {
                        isPeriod = false;
                        break;
                    }
                }
                if(isPeriod)
                    return to_string(t);
            }
            t = s.find(c, t+1);
        }
        return to_string(s.size());
}
