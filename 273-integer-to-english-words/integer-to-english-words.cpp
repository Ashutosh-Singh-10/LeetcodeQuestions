class Solution {
public:
    string give_string(int temp)
    {
            switch (temp)
            {
                case 1:
                    return "One";
                case 2:
                    return "Two";
                 case 3:
                  return "Three";
                 case 4:
                  return "Four";
                 case 5:
                  return "Five";
                 case 6:
                  return "Six";
                 case 7:
                  return "Seven";
                 case 8:
                  return "Eight";
                 case 9:
                  return "Nine";
            }
        return "";
    }
string eleven_string(int temp)
{
    switch (temp)
        {
                case 10:
                return "Ten";
                case 11:
                return "Eleven";
                case 12:
                return "Twelve";
                case 13:
                return "Thirteen";
                case 14:
                return "Fourteen";
                case 15:
                return "Fifteen";
                case 16:
                return "Sixteen";
                case 17:
                return "Seventeen";
                case 18:
                return "Eighteen";
                case 19:
                return "Nineteen";
        }
        cout<<"HII";
        return "";
}
    string ten_string(int temp)
    {
        switch (temp)
            {
            
                    case 2:
                    return "Twenty";
                    case 3:
                    return "Thirty";
                    case 4:
                    return "Forty";
                    case 5:
                    return "Fifty";
                    case 6:
                    return "Sixty";
                    case 7:
                    return "Seventy";
                    case 8:
                    return "Eighty";
                    case 9:
                    return "Ninety";
            }
            return "";
    }
    string calculate(int num)
    {
        if(num==0) return "";
        string ans="";
        int temp=num/100;
        if(temp)
        {
            ans+=give_string(temp)+" Hundred ";    
        }
        num%=100;
        temp=num/10;
        cout<<num<<"  "<<temp;
        if(temp==1)
        {
            ans+=eleven_string(num)+" ";
            cout<<"ans "<<ans;
        }
        else 
        {
            if(temp)
            {
                ans+=ten_string(temp)+" ";
            }
            
            
            num%=10;

            if(num)
            {
                ans+=give_string(num)+" ";
            }
            
        }

        return ans;
    }
    string numberToWords(int num) 
    {

    if(num==0) return "Zero";
        string ans="";
        if(num>=1000000000)
        {
            ans+=calculate(num/1000000000);
            ans+="Billion ";
            num%=1000000000;
        }
        if(num>=1000000)
        {
            ans+=calculate(num/1000000);
            ans+="Million ";
            num%=1000000;
        }
        if(num>=1000)
        {
            cout<<"val="<<num/1000<<endl;
            ans+=calculate(num/1000);
            ans+="Thousand ";
            num%=1000;
        }

        ans+=calculate(num);
        return ans.substr(0,ans.length()-1);
        return ans;


        
    }
};