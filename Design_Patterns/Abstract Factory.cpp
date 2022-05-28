/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Button
{
   public:
   virtual void paint()=0;
};

class TextBox
{
    public:
    virtual void paint()=0;
};

class WindowsButton:public Button
{
    public:
    void paint()
    {
        cout<<"Painting WindowsButton\n";
        cout<<" _\n";
        cout<<"|_|\n\n";
    }
};

class WindowsTextBox:public TextBox
{
    public:
    void paint()
    {
        cout<<"Painting WindowsTextBox\n";
        cout<<"._______________________.\n";
        cout<<"|_______________________|\n\n";
    }
};

class MacButton:public Button
{
    public:
    void paint()
    {
        cout<<"Painting MacButton\n";
        cout<<".__.\n";
        cout<<"|__|\n\n";
    }
};

class MacTextBox:public TextBox
{
    public:
    void paint()
    {
        cout<<"Painting MacTextBox\n";
        cout<<".._______________________..\n";
        cout<<"||_______________________||\n";
        cout<<"||                       ||\n";
        cout<<"  _______________________  \n";
        cout<<"||_______________________||\n";
        cout<<"..                       ..\n\n";
    }
};

class LinuxButton:public Button
{
    public:
    void paint()
    {
        cout<<"Painting LinuxButton\n";
        cout<<".____.\n";
        cout<<"||__||\n\n";
    }
};

class LinuxTextBox:public TextBox
{
    public:
    void paint() {
        cout<<"Painting LinuxTextBox\n";
        cout<<"._______________________.\n";
        cout<<"._______________________.\n";
        cout<<"||                     ||\n";
        cout<<"._______________________.\n";
        cout<<"._______________________.\n\n";
        
    }
};

class GUIFactory
{
    public:
    virtual Button* _buttonFactory()=0;
    virtual TextBox* _textBoxFactory()=0;
};

class WinFactory:public GUIFactory
{
    public:
    Button* _buttonFactory()
    {
        return new WindowsButton();
    }
    TextBox* _textBoxFactory()
    {
        return new WindowsTextBox();
    }
};

class MacFactory:public GUIFactory
{
    public:
    Button* _buttonFactory()
    {
        return new MacButton();
    }
    TextBox* _textBoxFactory()
    {
        return new MacTextBox();
    }
};

class LinuxFactory:public GUIFactory
{
    public:
    Button* _buttonFactory()
    {
        return new LinuxButton();
    }
    TextBox* _textBoxFactory()
    {
        return new LinuxTextBox();
    }
};

int main()
{
    
    Button *btn = nullptr;
    TextBox *tbx = nullptr;
    GUIFactory* gFact = nullptr;
    
    gFact = new WinFactory();
    btn = gFact->_buttonFactory();
    tbx = gFact->_textBoxFactory();
    btn->paint();
    tbx->paint();
    
    gFact = new MacFactory();
    btn = gFact->_buttonFactory();
    tbx = gFact->_textBoxFactory();
    btn->paint();
    tbx->paint();
    
    gFact = new LinuxFactory();
    btn = gFact->_buttonFactory();
    tbx = gFact->_textBoxFactory();
    btn->paint();
    tbx->paint();
    return 0;
}
