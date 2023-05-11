# include <iostream>
# include <fstream>

using namespace std;

int main(){
    ifstream main_in("myfile.txt");

    if(!main_in){
        cout << "Error in opening the main file for input";
        return -1;
    }

    main_in.unsetf(ios::skipws);
    // Compile the code after commenting the above line!

    ofstream copy_out("copyfile.txt");

    if (!main_in)
    {
        cout << "Error in opening the copy file for output";
        return -1;
    }

    char ch;
    int num_char = 0;

    while(!main_in.eof()){
        main_in >> ch;

        if(ch != EOF){
            copy_out << ch;
            num_char++;
        }
    }

    main_in.close();
    copy_out.close();

    cout << "Total number of characters copied: " << num_char << endl;

    return 0;
}