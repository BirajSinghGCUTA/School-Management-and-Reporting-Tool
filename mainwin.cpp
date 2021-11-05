#include "mainwin.h"
#include <iostream>
#include <typeinfo>
#include <string.h>

Mainwin::Mainwin(){

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(600,350);
    set_title("SMART(School Management and Reporting Tool)");


    
    Gtk::Box *Vbox = Gtk::manage(new Gtk::VBox);                                               
    add(*Vbox);                                                                                


                    // MENU BAR
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);                                      
    Vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);                                            

                    // File item in Menu Bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));               
    menubar -> append(*menuitem_file);                                                          

                    //Menu inside File item
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());                                         
    menuitem_file -> set_submenu(*filemenu);                                                    

                    // NEW SCHOOL IN FILE
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));          
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});             
    filemenu->append(*menuitem_new);  

                    // Save IN FILE
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));          
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});             
    filemenu->append(*menuitem_save);

                    // SAVE AS in FILE
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Sa_ve As", true));          
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});             
    filemenu->append(*menuitem_save_as);  

                    // OPEN IN FILE
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));          
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});             
    filemenu->append(*menuitem_open);

                    // Quit in FILE
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));               
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});                  
    filemenu->append(*menuitem_quit);  

                    // INSERT IN MENU BAR
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));           
    menubar -> append(*menuitem_insert);                                                        

                    // MENU INSIDE INSERT ITEM
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());                                        
    menuitem_insert -> set_submenu(*insertmenu);                                                 

                    // NEW STUDENT IN INSERT
    Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("New _Student", true));         
    menuitem_new_student->signal_activate().connect([this] {this->on_new_student_click();});            
    insertmenu->append(*menuitem_new_student);                                                          

                    // NEW Parent IN INSERT
    Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("New _Parent", true));               
    menuitem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});                  
    insertmenu->append(*menuitem_new_parent);  
                    // NEW Course IN INSERT
    Gtk::MenuItem *menuitem_new_course = Gtk::manage(new Gtk::MenuItem("New Course"));               
    menuitem_new_course->signal_activate().connect([this] {this->on_new_course_click();});                  
    insertmenu->append(*menuitem_new_course);

                    // NEW  SECTION IN INSERT
    Gtk::MenuItem *menuitem_new_section = Gtk::manage(new Gtk::MenuItem("New Section"));               
    menuitem_new_section->signal_activate().connect([this] {this->on_new_section_click();});                  
    insertmenu->append(*menuitem_new_section);                                                        
                    
                    
                    
                    
                    //View in Menu Bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("View"));            
    menubar -> append(*menuitem_view);  

                     // Menu inside View item
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());                                        
    menuitem_view -> set_submenu(*viewmenu);   

                    // NEW  SECTION IN INSERT
    Gtk::MenuItem *menuitem_view_parentandstudent = Gtk::manage(new Gtk::MenuItem("Parents and Students"));               
    menuitem_view_parentandstudent->signal_activate().connect([this] {this->on_view_parentandstudent_click();});                  
    viewmenu->append(*menuitem_view_parentandstudent); 

                    // NEW  SECTION IN INSERT
    Gtk::MenuItem *menuitem_view_section = Gtk::manage(new Gtk::MenuItem("Sections"));               
    menuitem_view_section->signal_activate().connect([this] {this->on_view_sections_click();});                  
    viewmenu->append(*menuitem_view_section); 

                    // NEW  SECTION IN INSERT
    Gtk::MenuItem *menuitem_view_course = Gtk::manage(new Gtk::MenuItem("Courses"));               
    menuitem_view_course->signal_activate().connect([this] {this->on_view_courses_click();});                  
    viewmenu->append(*menuitem_view_course); 
                    
                    
                    
                    // Relate in Menu Bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("Relate", true));            
    menubar -> append(*menuitem_relate);                                                         

                    // Menu inside Relate item
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());                                        
    menuitem_relate -> set_submenu(*relatemenu);                                                 

                    //Student to Parent under relate
    Gtk::MenuItem *menuitem_student_to_parent = Gtk::manage(new Gtk::MenuItem("Student to Pa_rent", true));         
    menuitem_student_to_parent->signal_activate().connect([this] {this->on_student_parent_click();});             
    relatemenu->append(*menuitem_student_to_parent);    

                    // Help in menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);

                    // Menu inside Help item
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);  

                    //About inside of HELP   
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);     

                    //TOOLBAR
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    Vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);  

                    //NEW SCHOOL IN TOOLBAR

    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create a new file, ALT + N");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);

                    //Open School In TOOLBAR

    Gtk::ToolButton *open_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_school_button->set_tooltip_markup("Open a new file, ALT + O");
    open_school_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_school_button);  

                    //Save School  In TOOLBAR
    Gtk::ToolButton *save_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_school_button->set_tooltip_markup("Save a file, ALT + S");
    save_school_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(* save_school_button);

                    //Open School AS In TOOLBAR

    Gtk::ToolButton *save_as_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_school_button->set_tooltip_markup("Save a new file, ALT + V");
    save_as_school_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*save_as_school_button);

                    //SPACER
    Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep2);

                    //INSERT STUDENT
    Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"logo/student.png"});
    Gtk::ToolButton *new_student_button = Gtk::manage(new Gtk::ToolButton(* button1_image));
    new_student_button->set_tooltip_markup("Create a new student, ALT + S");
    new_student_button->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(* new_student_button);

                    //INSERT PARENT

    Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"logo/parents.png"});
    Gtk::ToolButton *new_parent_button = Gtk::manage(new Gtk::ToolButton(*button2_image));
    new_parent_button->set_tooltip_markup("Create a new parent, ALT + P");
    new_parent_button->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(* new_parent_button);

                    //RELATE
    Gtk::Image* button3_image = Gtk::manage(new Gtk::Image{"logo/relate.png"});
    Gtk::ToolButton *new_relate_button = Gtk::manage(new Gtk::ToolButton(*button3_image));
    new_relate_button->set_tooltip_markup("Create a new relation, ALT + R");
    new_relate_button->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(* new_relate_button);

    Gtk::SeparatorToolItem *sep3 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep3);

                    //New course
    Gtk::Image* button4_image = Gtk::manage(new Gtk::Image{"logo/course.png"});
    Gtk::ToolButton *new_course_button = Gtk::manage(new Gtk::ToolButton(*button4_image));
    new_course_button->set_tooltip_markup("Add a new course");
    new_course_button->signal_clicked().connect([this] {this->on_new_course_click();});
    toolbar->append(*new_course_button);

                    //New Section
    Gtk::Image* button5_image = Gtk::manage(new Gtk::Image{"logo/section.png"});
    Gtk::ToolButton *new_section_button = Gtk::manage(new Gtk::ToolButton(*button5_image));
    new_section_button->set_tooltip_markup("Add a new section");
    new_section_button->signal_clicked().connect([this] {this->on_new_section_click();});
    toolbar->append(*new_section_button);
    

    display = Gtk::manage(new Gtk::Label{show_data(), Gtk::ALIGN_START});
    Vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);

    Vbox->show_all();
    on_new_school_click();
};

Mainwin::~Mainwin(){}; 

void Mainwin::on_new_school_click(){
    students.clear();
    parents.clear();
    courses.clear();
    sections.clear();
    display -> set_text(show_data());
};

void Mainwin::on_view_parentandstudent_click(){
    display -> set_text(show_data());
}
void Mainwin::on_view_sections_click(){
    display -> set_text(show_data_sections());
}
void Mainwin::on_view_courses_click(){
    display -> set_text(show_data_courses());
}

void Mainwin::on_new_course_click(){
    //Attributes for courses
    Subject subject; 
    int grade;
    int _subject;

    std::string sec_text;
    int a = 0;
   


    for(Subject m = Subject::MATH; m <= Subject::ENGLISH; m =(Subject)((int)m + 1)){
        std::string str = std::to_string(a);
        sec_text += str + ". " + to_string(m) + "\n";
        a++;
    } 

   
    EntryDialog edialogCname{*this, "<big>Select Course</big>", true};
    edialogCname.set_secondary_text(sec_text);
    edialogCname.run();

    EntryDialog edialoggrade{*this, "<big>Grade(1-12)</big>", true};
    edialoggrade.run();

    try
    {
        if( edialogCname.get_text().size() == 0 || edialoggrade.get_text().size() == 0 || !isNumber(edialogCname.get_text()) || !isNumber(edialoggrade.get_text())) {
            throw std::runtime_error {"bad data"};
        }
        else{
            _subject = std::stoi(edialogCname.get_text());
            grade = std::stoi(edialoggrade.get_text());   
        }    
        if((_subject < 0 || _subject > a-1) || (grade < 0 || grade > 12)){
            throw std::runtime_error {"bad data"};
        }
    }
     catch(std::runtime_error e){
        std::cerr << "An exception occurred. Exception Nr. " << e.what() << '\n';
        Gtk::MessageDialog mdialog{*this, "Invalid Data Input"};
        mdialog.run();
        return;
    }

    subject = (Subject)(_subject+1);
    Course *c1 = new Course{subject, grade};
    courses.push_back(c1);
    display -> set_text(show_data_courses());

}


void Mainwin::on_new_section_click(){
   /* //Attributes for courses
    int year;
    int _course;
    int _semester;
    Semester semester;
    Teacher &teacher;
    std::stringstream ss;

    std::string sec_text;
    int a = 0;

    for(auto *p : courses) {
        std::string str = std::to_string(a);
        ss << str << ". "<< *p << '\n';
        a++;
    }   
    sec_text = ss.str();

    EntryDialog edialogCname{*this, "<big>Course</big>", true};
    edialogCname.set_secondary_text(sec_text);
    edialogCname.run();


    EntryDialog edialogYname{*this, "<big>Select Semester and year(2000-2050)</big>", true};
    edialogYname.add_button("Cancel", 0);
    edialogYname.add_button("Fall", 1);     
    edialogYname.add_button("Spring", 2);     
    edialogYname.add_button("Summer", 3);
    

    _semester = edialogYname.run();

    try
    {
        if( edialogCname.get_text().size() == 0 || edialogYname.get_text().size() == 0 || !isNumber(edialogCname.get_text()) || !isNumber(edialogYname.get_text())) {
            throw std::runtime_error {"bad data"};
        }
        else{
            _course = std::stoi(edialogCname.get_text());
            year = std::stoi(edialogYname.get_text());   
        }    
        if((_course < 0 || _course > a-1) || (year < 2000 || year > 2050) || (_semester < 1 || _semester > 3)){
            throw std::runtime_error {"bad data"};
        }
    }
     catch(std::runtime_error e){
        std::cerr << "An exception occurred. Exception Nr. " << e.what() << '\n';
        Gtk::MessageDialog mdialog{*this, "Invalid Data Input"};
        mdialog.run();
        return;
    }

    semester = (Semester)(_semester);
    Section *s1 = new Section{*courses[_course],semester, year};
    sections.push_back(s1);
    display -> set_text(show_data_sections());
    */
}


void Mainwin::on_save_click(){
    try {
            std::ofstream ofs{filename};
            ofs << students.size() << std::endl;
            for(auto *p : students) {
                p->save(ofs);
            }

            ofs << parents.size() << std::endl;
            for(auto *p : parents) {
                p->save(ofs);
            }
            ofs << courses.size() << std::endl;
            for(auto *p : courses) {
                p->save(ofs);
            }

            ofs << sections.size() << std::endl;
            for(auto *p : sections) {
                p->save(ofs);
            }
            if(!ofs) throw std::runtime_error{"Error writing file"};
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to save FILE"}.run();
        }
}

void Mainwin::on_save_as_click(){

    Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.smart");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        filename = dialog.get_filename();
        on_save_click();
    }
}
void Mainwin::on_open_click(){

    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.smart");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        on_new_school_click();
        try {
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            int size;
            ifs >> size;

            for(int i = 0; i < size; i++) {
                 Student *s1 = new Student{ifs};
                 students.push_back(s1);
            }

            ifs >> size;
            for(int i = 0; i < size; i++) {
                 Parent *p1 = new Parent{ifs};
                 parents.push_back(p1);
            }
        
            ifs >> size;
            for(int i = 0; i < size; i++) {
                 Course *p1 = new Course{ifs};
                 courses.push_back(p1);   
            }

            ifs >> size;
            for(int i = 0; i < size; i++) {
                 Section *p1 = new Section{ifs};
                 sections.push_back(p1);
            }
            if(!ifs) throw std::runtime_error{"File contents bad"};
            display -> set_text(show_data());
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open FILE"}.run();
        }
    }
}

void Mainwin::on_new_student_click(){
    std::string Name;
    std::string Email;
    int Grade;

    EntryDialog edialogname{*this, "<big>Student Name</big>", true};
    edialogname.run();
    Name = edialogname.get_text();

    EntryDialog edialogemail{*this, "<big>Student Email</big>", true};
    edialogemail.run();
    Email = edialogemail.get_text();

 
    EntryDialog edialoggrade{*this, "<big>Student Grade</big>", true};
    edialoggrade.run();
    
    try{
        if(Name.size() == 0 || Email.size() == 0 || edialoggrade.get_text().size() ==0 || !isNumber(edialoggrade.get_text())) {
            throw std::runtime_error {"bad data"};
        }
    }
    catch(std::runtime_error e){
        std::cerr << "An exception occurred. Exception Nr. " << e.what() << '\n';
        Gtk::MessageDialog mdialog{*this, "Invalid Data Input"};
        mdialog.run();
        return;
    }


        Grade = std::stoi(edialoggrade.get_text());
    
        Student *s1 = new Student{Name, Email, Grade};
        students.push_back(s1);

        display -> set_text(show_data());

};


void Mainwin::on_new_parent_click(){
    std::string Name;
    std::string Email;

    EntryDialog edialogname{*this, "<big>Parent Name</big>", true};
    edialogname.run();
    Name = edialogname.get_text();


    EntryDialog edialogemail{*this, "<big>Parent Email</big>", true};
    edialogemail.run();
    Email = edialogemail.get_text();

    try{
         if(Name.size() == 0 || Email.size() == 0 ) {
         throw std::runtime_error {"bad data"};
        }
    }

    catch(std::runtime_error e){
        std::cerr << "An exception occurred. Exception Nr. " << e.what() << '\n';
        Gtk::MessageDialog mdialog{*this, "Invalid Data Input"};
        mdialog.run();
        return;
    }

    Parent *p1 = new Parent{Name, Email};
    parents.push_back(p1);
    
    display -> set_text(show_data());
};

void Mainwin::on_student_parent_click(){
    int parent;
    int student;
    std::string sec_text;
    int a = 0;

     for(auto *p : students) {
        std::string str = std::to_string(a);
        sec_text += str + ". " +p->to_string() + "\n";
        a++;
    }    
    
    EntryDialog edialogSname{*this, "<big>Select Student</big>", true};
    edialogSname.set_secondary_text(sec_text);
    edialogSname.run();

    int b = 0;
    sec_text = "";

    for(auto *p : parents) {
        std::string str = std::to_string(b);
        sec_text += str + ". " + p->to_string() + "\n";
        b++;
    }    

    EntryDialog edialogPname{*this, "<big>Select Parent</big>", true};
    edialogPname.set_secondary_text(sec_text);
    edialogPname.run();

    try{
        if( edialogSname.get_text().size() == 0 || edialogPname.get_text().size() == 0 || !isNumber(edialogSname.get_text()) || !isNumber(edialogPname.get_text())) {
            throw std::runtime_error {"bad data"};
        }
        else{
        student = std::stoi(edialogSname.get_text());
        parent = std::stoi(edialogPname.get_text());

        if(student > (a-1) || parent > (b-1)) {
            throw std::runtime_error {"bad data"};
            }
        }
  
    }
    catch(std::runtime_error e){
        std::cerr << "An exception occurred. Exception Nr. " << e.what() << '\n';
        Gtk::MessageDialog mdialog{*this, "Invalid Data Input"};
        mdialog.run();
        return;
    }
        
        Parent* p1 = parents[parent];
        Student* s1 = students[student];
        s1->add_parent(*p1);
        p1 -> add_student(*s1);
    
        display -> set_text(show_data());
};

void Mainwin::on_quit_click(){
    close();
};

void Mainwin::on_about_click(){
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("SMART");
    auto logo = Gdk::Pixbuf::create_from_file("logo/logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 0.3.2");
    dialog.set_copyright("Copyright 2021");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Biraj Singh GC", "George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by SeekLogo, https://seeklogo.com/vector-logo/128095/smart",
        };
    dialog.set_artists(artists);
    dialog.run();
}

std::string Mainwin::show_data(){

    std::string data_to_show = "\n\n\n";

    data_to_show = "Students \n\n";

    for(auto *p : students) {
        data_to_show += p->full_info() + "\n";
    }
    data_to_show += "\n\n\n\n";
    data_to_show += "Parents\n";
    for(auto*p : parents) {
        data_to_show += p->full_info() + "\n";
    }

    return data_to_show;
}
std::string Mainwin::show_data_sections(){

    std::string data_to_show = "\n\n\n";
    std::stringstream ss;

    data_to_show = "Sections \n\n";

    for(auto *p : sections) {
       ss << *p << '\n';
    }
    data_to_show += ss.str();

    return data_to_show;
}

std::string Mainwin::show_data_courses(){

    std::string data_to_show = "\n\n\n";
    std::stringstream ss;
    data_to_show = "Courses \n\n";

    for(Course *p : courses) {
       ss << *p<< '\n';
    }
     data_to_show += ss.str();
    return data_to_show;
}

bool Mainwin::isNumber(std::string s)
{
    for (int i = 0; i < s.length(); i++)
        if (std::isdigit(s[i]) == false)
            return false;
 
    return true;
}