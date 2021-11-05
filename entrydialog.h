#ifndef __entrydialog_h
#define __entrydialog_h
#include "mainwin.h"

//THIS CODE WAS COPIED FROM https://github.com/prof-rice/cse1325-prof/tree/main/14/02_entrydialog AS INSTRUCTED

class EntryDialog : public Gtk::MessageDialog {
  public:
    // This constructor is identical to Gtk::MessageDialog
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1MessageDialog.html
    EntryDialog(Gtk::Window& parent,
                const Glib::ustring& message, 
                bool use_markup=false, 
                Gtk::MessageType type=Gtk::MESSAGE_OTHER, 
                Gtk::ButtonsType buttons=Gtk::BUTTONS_OK, 
                bool modal=false);

    // These methods are identical to those of the same name in Gtk::Entry
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Entry.html
    void set_text (const Glib::ustring& text);
    Glib::ustring get_text () const;
  private:
    Gtk::Entry* entry;
};

#endif