#ifndef __mainwin_h
#define __mainwin_h

#include <gtkmm.h>
#include "parent.h"
#include "student.h"
#include "section.h"
#include "entrydialog.h"
#include "teacher.h"
#include "transcript.h"

class Mainwin : public Gtk::Window{
    public:
        Mainwin();
        virtual ~Mainwin();    
    protected:
        void on_new_school_click();
        void on_save_click();
        void on_save_as_click();
        void on_open_click();
        void on_new_student_click();
        void on_new_parent_click();
        void on_about_click();
        void on_student_parent_click();
        void on_quit_click();
        void on_new_course_click();
        void on_new_section_click();
        void on_view_parentandstudent_click();
        void on_view_sections_click();
        void on_view_courses_click();

    private:
        std::string filename;
        std::string show_data();                   //modified to update the display 
        std::string show_data_sections();
        std::string show_data_courses();
        std::vector <Student*> students;           //allocating object in heap and storing the pointers instead.
        std::vector <Parent*> parents;
        std::vector <Section*> sections;
        std::vector <Course*> courses;
        std::vector <Teacher*> teachers;
        std::vector <Transcript*> transcripts;

        Gtk::Label *display;
        bool isNumber(std::string s);              //to check if input is a number


};


#endif