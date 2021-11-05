CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: smart

debug: CXXFLAGS += -g
debug: smart

smart: main.o mainwin.o entrydialog.o parent.o student.o person.o course.o semester.o subject.o section.o transcript.o grade.o teacher.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o entrydialog.o parent.o student.o person.o course.o semester.o subject.o section.o transcript.o grade.o teacher.o $(GTKFLAGS) -o smart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

entrydialog.o: entrydialog.cpp *.h		
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

semester.o: semester.cpp *.h
	$(CXX) $(CXXFLAGS) -c semester.cpp -o semester.o

subject.o: subject.cpp *.h
	$(CXX) $(CXXFLAGS) -c subject.cpp -o subject.o

course.o: course.cpp *.h
	$(CXX) $(CXXFLAGS) -c course.cpp -o course.o

section.o: section.cpp *.h
	$(CXX) $(CXXFLAGS) -c section.cpp -o section.o

transcript.o: section.cpp *.h
	$(CXX) $(CXXFLAGS) -c transcript.cpp -o transcript.o

teacher.o: teacher.cpp *.h
	$(CXX) $(CXXFLAGS) -c teacher.cpp -o teacher.o

grade.o: grade.cpp *.h
	$(CXX) $(CXXFLAGS) -c grade.cpp -o grade.o

clean: 
	rm -f *.o *.gch *~ a.out cli test main smart