// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PHYSICAL_CONTEXT_WINDOW_H
#define PHYSICAL_CONTEXT_WINDOW_H

#include <string>
#include <map>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Choice.H>

class physicalContextWindow {
public:
  Fl_Window *win;
  Fl_Tabs *tab;
  Fl_Group *group[2];
  Fl_Box *box[10];
  Fl_Input_Choice *input[10];
  Fl_Check_Button *butt[10];
  Fl_Value_Input *value[10];
  Fl_Choice *choice[10];
  std::string mode;
  bool append;
  std::map<std::pair<int, int>, std::string> physicalTags;
  std::map<std::string, std::pair<int, int> > physicalNames;

public:
  physicalContextWindow(int deltaFontSize = 0);
  ~physicalContextWindow() { Fl::delete_widget(win); }
  void show(const std::string &what, bool remove);
  void hide() { win->hide(); }
  void updateOnelabWidgets();
};

#endif
