# include <iostream>

using namespace std;

void showflags();

int main(){

    cout << "\n---------------------------\tDefault settings\t--------------------------------\n";
    showflags();

    cout.setf(ios::oct | ios::showbase | ios::fixed);

    cout << "\n---------------------------\tChanged settings\t--------------------------------\n";
    showflags();
    cout << endl;

    return 0;
}

void showflags(){
    ios::fmtflags f;
    f = cout.flags();   //get flag settings

    if(f & ios::skipws){
        cout << "skipws on" << endl;
    }
    else{
        cout << "skipws off" << endl;
    }

    if (f & ios::left)
    {
        cout << "left on" << endl;
    }
    else
    {
        cout << "left off" << endl;
    }

    if (f & ios::right)
    {
        cout << "right on" << endl;
    }
    else
    {
        cout << "right off" << endl;
    }

    if (f & ios::internal)
    {
        cout << "internal on" << endl;
    }
    else
    {
        cout << "internal off" << endl;
    }

    if (f & ios::dec)
    {
        cout << "dec on" << endl;
    }
    else
    {
        cout << "dec off" << endl;
    }

    if (f & ios::oct)
    {
        cout << "oct on" << endl;
    }
    else
    {
        cout << "oct off" << endl;
    }

    if (f & ios::hex)
    {
        cout << "hex on" << endl;
    }
    else
    {
        cout << "hex off" << endl;
    }

    if (f & ios::showbase)
    {
        cout << "showbase on" << endl;
    }
    else
    {
        cout << "showbase off" << endl;
    }

    if (f & ios::showpoint)
    {
        cout << "showpoint on" << endl;
    }
    else
    {
        cout << "showpoint off" << endl;
    }

    if (f & ios::showpos)
    {
        cout << "showpos on" << endl;
    }
    else
    {
        cout << "showpos off" << endl;
    }

    if (f & ios::uppercase)
    {
        cout << "uppercase on" << endl;
    }
    else
    {
        cout << "uppercase off" << endl;
    }

    if (f & ios::scientific)
    {
        cout << "scientific on" << endl;
    }
    else
    {
        cout << "scientific off" << endl;
    }

    if (f & ios::fixed)
    {
        cout << "fixed on" << endl;
    }
    else
    {
        cout << "fixed off" << endl;
    }

    if (f & ios::unitbuf)
    {
        cout << "unitbuf on" << endl;
    }
    else
    {
        cout << "unitbuf off" << endl;
    }

    if (f & ios::boolalpha)
    {
        cout << "boolalpha on" << endl;
    }
    else
    {
        cout << "boolalpha off" << endl;
    }
}
