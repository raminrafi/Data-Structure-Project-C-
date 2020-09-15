#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
bool stringcompare(char x1[], char x2[])
{
	if (strlen(x1) != strlen(x2))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < strlen(x1); i++)
		{
			if (x1[i] != x2[i])
			{
				return false;
			}
		}
	}
	return true;
}

char * stringcopy(char * str1, char * str2)
{
	int i = 0;
	while (str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return str1;
}

struct classlist
{
	int count;
	char names[8005][15];
	char rollno[8005][10];
};

template <typename T>
struct node
{
	T course[60];
	T time[15];
	T room[30];
	T sec[30];
	T day[20];
	int num;
	classlist * aptr;
	node * next;
};

template <typename T>
class LLADT
{
public:
    node <T> * first;
	LLADT()
	{
		first = NULL;
	}
	void insert(node <T> * a)
	{
		node <T> * temp;
		temp = new node <T>;
		int i = 0, j = 0, k = 0, z=0, y=0, x=0;
		for (; a->course[i] != '\0'; i++)
		{
			temp->course[i] = a->course[i];
		}
		temp->course[i] = '\0';
        for(; a->time[j] != '\0'; j++)
        {
            temp->time[j] = a->time[j];
        }
        temp->time[j]='\0';
        for(; a->room[k] != '\0'; k++)
        {
            temp->room[k] = a->room[k];
        }
        temp->room[k]='\0';
        for(; a->sec[z] != '\0'; z++)
        {
            temp->sec[z] = a->sec[z];
        }
        temp->sec[z]='\0';
        for(; a->day[y] != '\0'; y++)
        {
            temp->day[y] = a->day[y];
        }
        temp->day[y]='\0';
		temp->aptr = a->aptr;
		temp->next = NULL;
		if (first == 0)
		{
			first = temp;
		}
		else
		{
			node <T> * curr = first;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
	bool search(T rolln[])
	{
		node <T> * curr = first;
		for (int i = 0; curr != 0; i++)
		{
			if (strcmp(curr->aptr->rollno[i], rolln) == true)
			{
				return true;
			}
			else
				curr = curr->next;
		}
		return false;
	}

	int count()
	{
		int num = 0;
		node <T>* curr = first;
		while (curr->next != NULL)
		{
			num++;
			curr = curr->next;
		}
		return num;
	}
	void print()
	{
		node <char> * curr = first;
		while (curr != 0)
		{
			cout << curr->course<<" ";
			cout << curr->sec <<" ";
			cout << curr->time<<" ";
			cout << curr->day<< " ";
			cout << curr->room<<endl;
			if (curr->aptr != NULL)
			{
				for (int i = 0; i<curr->aptr->count; i++)
				{
					cout << curr->aptr->names[i] << " ";
					cout << curr->aptr->rollno[i] << " ";
					cout << endl;
				}
			}
			cout << endl;
			curr = curr->next;
		}
	}
	void printCoursee(char day[],char time[], char classroom[])
	{
	    node <char> *curr=first;
	    while (curr!=0)
        {
            if ((stringcompare(curr->day,day)==true) && (stringcompare(curr->time,time)== true) && (stringcompare(curr->room, classroom) == true))
            {
                cout<<curr->course<<" ";
                cout<<curr->sec<<" ";
            }
            curr=curr->next;
        }
	}
	void printCourseTimingss(char coursenamee[])
	{
	    node <char> *curr=first;
	    while (curr!=0)
        {
            if(stringcompare(curr->course,coursenamee) == true)
            {
                cout<<curr->day<<" ";
                cout<<curr->time<<endl;
            }
            curr=curr->next;
        }
	}
	void clashes()
	{
	    ofstream fout("clash.txt");
	    if(fout.is_open())
        {
            node <char>*curr1=first;
            node <char>*curr2=first;
            char rno[20],dayy[10],timee[10];
            int j=0,i=0,k=0;
            while(curr1!=0)
            {
                while(curr2!=0)
                {
                    if(stringcompare(curr1->aptr->rollno[i],curr2->aptr->rollno[j])==true)
                    {
                        if(stringcompare(curr1->day,curr2->day) == true && stringcompare(curr1->time,curr2->time)==true)
                        {
                            fout<<curr1->aptr->rollno[k]<<" ";
                            fout<<curr1->course<<" ";
                            fout<<curr1->sec<<" "<<endl;
                            fout<<curr2->course<<" ";
                            fout<<curr2->sec<<endl;
                            fout<<curr2->day<<" ";
                            fout<<curr2->time<<" ";
                        }
                    }
                    k++;
                    curr2=curr2->next;
                     j++;
                }
                k=0;
                curr1=curr1->next;
                curr2=first;
                i++;
            }
        }
	}
	/*void printTimetable(char coursenamee[], char secc[])
	{
	    int i=0;
	    cout<<coursenamee<<" "<<secc<<endl<<endl;
	    node <char> *curr=first;
	    while(curr!=0)
        {
            if(stringcompare(curr->course,coursenamee) == false)
            {
                flag=false;
            }
            if(flag == true)
            {
                cout<<curr->day<<" ";
                cout<<curr->time<<endl;
            }
            curr=curr->next;
            flag=true;
        }
	}*/
	void printL1()
	{
		node <char> * curr = first;
		while (curr != 0)
		{
			cout << curr->course<<endl;
			cout << curr->time<< " ";
			cout << curr->room<< " ";
			cout<< curr->sec<<" ";
			cout<<curr->day<<" ";
			cout << endl;
			curr = curr->next;
		}
	}
	~LLADT()
	{
		node <T>  * curr = first;
		while (curr != NULL)
		{
			first = first->next;
			delete curr;
			curr = first;
		}
	}
};

class TTADT
{
	LLADT <char> L1;
	LLADT <char> L2;
	int countt;
public:
	void load(char filename[])
	{
		node <char> * ptr;
		//-------------------------------------------------------------------------------
		char * buff = new char[1000];
		char * newtemp;
		ifstream fin("timetableorg.csv");
		fin.getline(buff, 1000, '\n');
		for (int i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] != ',')
			{
				cout << buff[i];
			}
		}
		cout << endl;
		//----------------------------------------------------------------------------------
		fin.getline(buff, 1000, '\n');
		cout << buff[0] << endl;

		//----------------------------------------------------------------------------------
		fin.getline(buff, 1000, '\n');
		int i = 0;
		for (; buff[i] != ','; i++)
			cout << buff[i];
		i = i + 2;
		cout << "\t\t";
		for (; buff[i] != '\0'; i++)
		{
			if (buff[i] == ',')
			{
				cout << "\t";
			}
			else
				cout << buff[i];
		}
		cout << endl;
		//---------------------------------------------------------------------------------------
		fin.getline(buff, 1000, '\n');
		i = 0;
		for (; buff[i] != ','; i++)
			cout << buff[i];
		i++;
		cout << "\t";
		for (; buff[i] != ','; i++)
			cout << buff[i];
		i++;
		cout << "\t";
		for (; buff[i] != '\0'; i++)
		{
			if (buff[i] == ',')
			{
				cout << "                                       ";
				i = i + 5;
			}
			else
				cout << buff[i];
		}
		cout << endl;
		//---------------------------------------------------------------------------------------
		i = 0;
		int a = 0;
		for (; i < 128; i++)
		{
			newtemp = new char[100];
			int k = 0;
			fin.getline(buff, 1000, '\n');
			for (; buff[k] != ','; k++)
				cout << buff[k];
			k++;
			cout << "\t";
			for (int z = 0; z < 13; z++)
			{
				for (; buff[k] != ','; k++)
					cout << buff[k];
				cout << "\t";
				int m = 0;
				for (int l = 0; l < 6; l++)
				{
					if (buff[k] == ',')
						k++;
					else
					{
						for (; buff[k] != ','; m++, k++)
						{
							newtemp[m] = buff[k];
							if (buff[k + 1] == ',')
								newtemp[m + 1] = '\0';
						}
					}
				}
				if (m == 0)
				{
					newtemp[0] = '\0';
				}
				int n = 0;
				if (newtemp[0] != '\0')
				{
					ptr = new node <char>;
					strcpy(ptr->course, newtemp);
                    if(z==0)
                    {
                       strcpy(ptr->time,"08:00am");

                    }
                    else if(z==1)
                    {
                        strcpy(ptr->time,"09:00am");

                    }
                    else if(z==2)
                    {
                        strcpy(ptr->time,"10:00am");

                    }
                    else if(z==3)
                    {
                        strcpy(ptr->time,"11:00am");

                    }
                    else if(z==4)
                    {
                        strcpy(ptr->time,"12:00pm");

                    }
                    else if(z==5)
                    {
                        strcpy(ptr->time,"01:00pm");

                    }
                    else if(z==6)
                    {
                        strcpy(ptr->time,"02:00pm");

                    }
                    else if(z==7)
                    {
                        strcpy(ptr->time,"03:00pm");

                    }
                    else if(z==8)
                    {
                        strcpy(ptr->time,"04:00pm");

                    }
                    else if(z==9)
                    {
                        strcpy(ptr->time,"05:00pm");

                    }
                    else if(z==10)
                    {
                        strcpy(ptr->time,"06:00pm");

                    }
                    else if(z==11)
                    {
                        strcpy(ptr->time,"07:00pm");
                    }
                    else
                    {
                        strcpy(ptr->time,"08:00pm");
                    }
                    if(i==0 || i==25 || i==51 || i==77 || i==103)
                    {
                        strcpy(ptr->room,"CS-1");
                    }
                    else if(i==1 || i==26|| i==52 || i==78 || i==104)
                    {
                        strcpy(ptr->room,"CS-2");
                    }
                    else if(i==2 || i==27 || i==53 || i==79 || i==105)
                    {
                        strcpy(ptr->room,"CS-3");
                    }
                    else if(i==3 || i==28 || i==54 || i==80 || i==106)
                    {
                        strcpy(ptr->room,"CS-4");
                    }
                    else if(i==4 || i==29 || i==55 || i==81 || i==107)
                    {
                        strcpy(ptr->room,"CS-5");
                    }
                    else if(i==5 || i==30 || i==56 || i==82 || i==108)
                    {
                        strcpy(ptr->room,"CS-6");
                    }
                    else if(i==6 || i==31 || i==57 || i==83 || i==109)
                    {
                        strcpy(ptr->room,"CS-7");
                    }
                    else if(i==7 || i==32 || i==58 || i==84 || i==110)
                    {
                        strcpy(ptr->room,"CS-8");
                    }
                    else if(i==8 || i==33 || i==59 || i==85 || i==111)
                    {
                        strcpy(ptr->room,"CS-9");
                    }
                    else if(i==9 || i==34 || i==60 || i==86 || i==112)
                    {
                        strcpy(ptr->room,"CS-10");
                    }
                    else if(i==10 || i==35 || i==61 || i==87 || i==113)
                    {
                        strcpy(ptr->room,"CS-11");
                    }
                    else if(i==11 || i==36 || i==62 || i==88 || i==114)
                    {
                        strcpy(ptr->room,"CS-15");
                    }
                    else if(i==12 || i==37 || i==63 || i==89 || i==115)
                    {
                        strcpy(ptr->room,"CS-16");
                    }
                    else if(i==13 || i==38 || i==64 || i==90 || i==116)
                    {
                        strcpy(ptr->room,"Seminar Hall");
                    }
                    else if(i==14 || i==39 || i==65 || i==91 || i==117)
                    {
                        strcpy(ptr->room,"CE-2");
                    }
                    else if(i==15 || i==40 || i==66 || i==92  || i==118)
                    {
                        strcpy(ptr->room,"CE-3");
                    }
                    else if(i==16 || i==41 || i==67 || i==93  || i==119)
                    {
                        strcpy(ptr->room,"English Lab-1");
                    }
                    else if(i==17 || i==42 || i==68 || i==94  || i==120)
                    {
                        strcpy(ptr->room,"English Lab-2");
                    }
                    else if(i==18 || i==43 || i==69 || i==95  || i==121)
                    {
                        strcpy(ptr->room,"Lab(CS-1)");
                    }
                    else if(i==19 || i==44 || i==70 || i==96 || i==122)
                    {
                        strcpy(ptr->room,"Lab(CS-4)");
                    }
                    else if(i==20 || i==45 || i==71 || i==97  || i==123)
                    {
                        strcpy(ptr->room,"Lab(CS-6)");
                    }
                    else if(i==21 || i==46 || i==72 || i==98  || i==124)
                    {
                        strcpy(ptr->room,"Lab(CS-9)");
                    }
                    else if(i==22 || i==47 || i==73 || i==99 || i==125)
                    {
                        strcpy(ptr->room,"Lab(CS-10)");
                    }
                    else if(i==23 || i==48 || i==74 || i==100 || i==126)
                    {
                        strcpy(ptr->room,"Physics Lab");
                    }
                    else
                    {
                        strcpy(ptr->room,"Micro Lab");
                    }
                    if((i>=0) && (i<26))
                    {
                        strcpy(ptr->day,"Monday");
                    }
                    else if((i>=26) && (i<51))
                    {
                        strcpy(ptr->day,"Tuesday");
                    }
                    else if((i>=51) && (i<76))
                    {
                        strcpy(ptr->day,"Wednesday");
                    }
                    else if((i>=76) && (i<101))
                    {
                        strcpy(ptr->day,"Thursday");
                    }
                    else
                    {
                        strcpy(ptr->day,"Friday");
                    }
					L1.insert(ptr);
				}
				for (int l = 0; newtemp[l] != '\0'; l++)
				{
					cout << newtemp[l];
					n++;
				}
				while (n < 40)
				{
					cout << " ";
					n++;
				}
			}
			delete[] newtemp;
			cout << endl;
		}
		L1.printL1();
	}
    void printCourse(char day[], char time[], char classroom[])
    {
        L1.printCoursee(day,time,classroom);
    }
    void printCourseTimings(char coursename[])
    {
        L1.printCourseTimingss(coursename);
    }
    void printStudentTimetable(char roll_no[])
    {
        node <char>*ptr = new node <char>;
		ptr->aptr = new classlist;
		ifstream fin("dataa.csv");
		if (fin.is_open())
		{
			ptr->aptr->count = 0;
			for (int i = 0; fin.eof() == false; i++)
			{
                fin.getline(ptr->aptr->rollno[i], 10, ',');
                fin.getline(ptr->aptr->names[i], 10, ',');
                fin.getline(ptr->course, 50, ',');
                fin.getline(ptr->sec, 30, '\n');
                ptr->aptr->count++;
				if(stringcompare(ptr->aptr->rollno[i],roll_no)== true)
                {
                    cout<<ptr->course<<" ";
                    cout<<ptr->sec<<endl;
                    L1.printCourseTimingss(ptr->course);
                }
			}
		}
    }
    void saveClashes()
    {
       L2.clashes();
    }
	void loadStudentInfo(char filename[])
	{
		int j = 0;
		char buffer[200];
		node <char>*ptr;
		char p[20], q[20], r[60], s[30];
		ifstream fin2("data.csv");
		if (fin2.is_open())
		{
			int i = 0;
			fin2.getline(buffer, 200, '\n');
			ptr = new node<char>;
			ptr->aptr = new classlist;
			ptr->aptr->count = 0;
			fin2.getline(p, 10, ',');
			fin2.getline(q, 10, ',');
			fin2.getline(r, 50, ',');
			fin2.getline(s, 30, '\n');
			ptr->aptr->count++;
			stringcopy(ptr->aptr->rollno[0], p);
			stringcopy(ptr->aptr->names[0], q);
			stringcopy(ptr->course, r);
			stringcopy(ptr->sec, s);
			while (fin2.eof() == false)
			{
				i++;
				fin2.getline(p, 10, ',');
				fin2.getline(q, 10, ',');
				fin2.getline(r, 50, ',');
				fin2.getline(s, 30, '\n');
				if((stringcompare(r,"Advance Database Concepts")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Advanced Programming")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Applied Physics")==true) && (stringcompare(s,"CS-H")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Applied Physics")==true) && (stringcompare(s,"CS-G")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Arabic Language")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Applied Physics")==true) && (stringcompare(s,"CS-G")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Artificial Intelligence")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Artificial Intelligence")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"01:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Artificial Intelligence")==true) && (stringcompare(s,"CS-E")==true))
                {
                    stringcopy(ptr->time,"04:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Artificial Intelligence")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Artificial Intelligence")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Artificial Intelligence")==true) && (stringcompare(s,"CS-F")==true))
                {
                    stringcopy(ptr->time,"04:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Calculus and Ana. Geometry")==true) && (stringcompare(s,"CS-G")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Calculus and Ana. Geometry")==true) && (stringcompare(s,"CS-H")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-H1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-D1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-B1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-C1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-G1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-E1")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-F1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-H2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-D2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-B2")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-C2")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-G2")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-E2")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Communication & Presentation Skills")==true) && (stringcompare(s,"CS-F2")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Comp. Org. & Assembly Lang.  Lab")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"01:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Comp. Org. & Assembly Lang.  Lab")==true) && (stringcompare(s,"CS-B1")==true))
                {
                    stringcopy(ptr->time,"01:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Comp. Org. & Assembly Lang.  Lab")==true) && (stringcompare(s,"CS-C1")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Comp. Org. & Assembly Lang.  Lab")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"01:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Comp. Org. & Assembly Lang.  Lab")==true) && (stringcompare(s,"CS-B2")==true))
                {
                    stringcopy(ptr->time,"01:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Comp. Org. & Assembly Lang.  Lab")==true) && (stringcompare(s,"CS-C2")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Compiler Construction")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"04:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Computer Architecture")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Computer Architecture")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Computer Networks")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Computer Networks")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Computer Networks Lab")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"10:00am");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Computer Networks Lab")==true) && (stringcompare(s,"CS-B1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Computer Networks Lab")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"10:00am");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Computer Networks Lab")==true) && (stringcompare(s,"CS-B2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Computer Programming")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"10:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Computer Programming Lab")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Computer Programming Lab")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Data Science")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"01:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Data Science")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Data Structures")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Data Structures")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Data Structures")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Database Systems")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Database Systems")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Database Systems")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Database Systems")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Database Systems")==true) && (stringcompare(s,"CS-E")==true))
                {
                    stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-B1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-C1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-D1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-E1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-B2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-C2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-D2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Database Systems Lab")==true) && (stringcompare(s,"CS-E2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Design & Analysis of Algorithms")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Design & Analysis of Algorithms")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Design & Analysis of Algorithms")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Design & Analysis of Algorithms")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Design & Analysis of Algorithms")==true) && (stringcompare(s,"CS-E")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Design & Analysis of Algorithms")==true) && (stringcompare(s,"CS-F")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Differential Equations")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Differential Equations")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Differential Equations")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Differential Equations (Cal II)")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Differential Equations (Cal II)")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Differential Equations (Cal II)")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Differential Equations (Cal II)")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }

                else if((stringcompare(r,"Differential Equations (Cal II)")==true) && (stringcompare(s,"CS-E")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Differential Equations (Cal II)")==true) && (stringcompare(s,"CS-F")==true))
                {
                    stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Digital Image Processing")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }

                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-E")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-B1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-C1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-D1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }

                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-E1")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-B2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-C2")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-D2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }

                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-E2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-F1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-F2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-H2")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                 else if((stringcompare(r,"Digital Logic Design")==true) && (stringcompare(s,"CS-H1")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Enterprise Information System")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Entrepreneurship")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"French Language")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"French Language")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Fundamental of Computer Vision")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Fundamental of Computer Vision")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Human Computer Interaction")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Human Computer Interaction")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Human Computer Interaction")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Human Computer Interaction")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Human Computer Interaction")==true) && (stringcompare(s,"CS-E")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Human Computer Interaction")==true) && (stringcompare(s,"CS-F")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Information Retrieval")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Mass Communication")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Modern Politics & Government")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Network Security")==true) && (stringcompare(s,"CS")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Numerical Methods")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Numerical Methods")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Numerical Methods")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Numerical Methods")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Object Oriented  Analysis & Design")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Wednesday");
                }
                  else if((stringcompare(r,"Object Oriented  Analysis & Design")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Object Oriented  Analysis & Design")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                  else if((stringcompare(r,"Object Oriented  Analysis & Design")==true) && (stringcompare(s,"CS-B1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Object Oriented  Analysis & Design")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                  else if((stringcompare(r,"Object Oriented  Analysis & Design")==true) && (stringcompare(s,"CS-B2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Object Oriented Programming")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                  else if((stringcompare(r,"Object Oriented Programming")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Object Oriented Programming")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                  else if((stringcompare(r,"Object Oriented Programming")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Object Oriented Programming")==true) && (stringcompare(s,"CS-E")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                  else if((stringcompare(r,"Object Oriented Programming")==true) && (stringcompare(s,"CS-F")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-A1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                  else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-B1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-C1")==true))
                {
                     stringcopy(ptr->time,"02:00pm");
                        stringcopy(ptr->day,"Monday");
                }
                  else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-D1")==true))
                {
                     stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-E1")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                  else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-F1")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-A2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                  else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-B2")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Wednesday");
                }
                else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-C2")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                  else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-D2")==true))
                {
                     stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-E2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                  else if((stringcompare(r,"Object Oriented Programming Lab")==true) && (stringcompare(s,"CS-F2")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Operating Systems")==true) && (stringcompare(s,"CS-A")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                  else if((stringcompare(r,"Operating Systems")==true) && (stringcompare(s,"CS-B")==true))
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Operating Systems")==true) && (stringcompare(s,"CS-C")==true))
                {
                    stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                  else if((stringcompare(r,"Operating Systems")==true) && (stringcompare(s,"CS-D")==true))
                {
                    stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Operating Systems")==true) && (stringcompare(s,"CS-E")==true))
                {
                  stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-A1")==true))
                {
                  stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-A2")==true))
                {
                 stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-B1")==true))
                {
                  stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-B2")==true))
                {
                  stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-C1")==true))
                {
                  stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-C2")==true))
                {
                  stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-D1")==true))
                {
                  stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-D2")==true))
                {
                    stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-E1")==true))
                {
                  stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                else if((stringcompare(r,"Operating Systems Lab")==true) && (stringcompare(s,"CS-E2")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Friday");
                }
                 else if((stringcompare(r,"Organizational Behavior")==true) && (stringcompare(s,"CS")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Philosophy")==true) && (stringcompare(s,"CS")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-C")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-D")==true))
                {
                   stringcopy(ptr->time,"12:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-E")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-F")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-G")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Pakistan Studies")==true) && (stringcompare(s,"CS-H")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Professional Issues in IT")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Professional Issues in IT")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Professional Issues in IT")==true) && (stringcompare(s,"CS-C")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Programming Fundamentals Lab")==true) && (stringcompare(s,"CS-G1")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Wednesday");
                }
                 else if((stringcompare(r,"Programming Fundamentals Lab")==true) && (stringcompare(s,"CS-G2")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Wednesday");
                }
                 else if((stringcompare(r,"Programming Fundamentals Lab")==true) && (stringcompare(s,"CS-H1")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Programming Fundamentals Lab")==true) && (stringcompare(s,"CS-H2")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Programming Fundamentals Lab")==true) && (stringcompare(s,"CS-I1")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                 else if((stringcompare(r,"Programming Fundamentals Lab")==true) && (stringcompare(s,"CS-I2")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Friday");
                }
                 else if((stringcompare(r,"Programming Fundamentals")==true) && (stringcompare(s,"CS-G")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Programming Fundamentals")==true) && (stringcompare(s,"CS-H")==true))
                {
                   stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Programming Fundamentals")==true) && (stringcompare(s,"CS-I")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Project-I")==true) && (stringcompare(s,"CS")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Thursday");
                }
                 else if((stringcompare(r,"Psychology")==true) && (stringcompare(s,"CS")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Sociology")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Sociology")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Software Engineering")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Software Engineering")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                 else if((stringcompare(r,"Software for Mobile Devices")==true) && (stringcompare(s,"CS-C")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Software for Mobile Devices")==true) && (stringcompare(s,"CS-D")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Software for Mobile Devices")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Software for Mobile Devices")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                 else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"03:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-C")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-D")==true))
                {
                  stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-E")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-F")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-G")==true))
                {
                   stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Technical & Business Writing")==true) && (stringcompare(s,"CS-H")==true))
                {
                   stringcopy(ptr->time,"12:00pm");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Theory of Automata")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Theory of Automata")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Total Quality Management")==true) && (stringcompare(s,"CS")==true))
                {
                   stringcopy(ptr->time,"08:00am");
                    stringcopy(ptr->day,"Monday");
                }
                else if((stringcompare(r,"Web Programming")==true) && (stringcompare(s,"CS-A")==true))
                {
                   stringcopy(ptr->time,"09:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else if((stringcompare(r,"Web Programming")==true) && (stringcompare(s,"CS-B")==true))
                {
                   stringcopy(ptr->time,"11:00am");
                    stringcopy(ptr->day,"Tuesday");
                }
                else
                {
                    stringcopy(ptr->time,"02:00pm");
                    stringcopy(ptr->day,"Tuesday");
                }
				if (stringcompare(r, ptr->course) == false)
				{
					L2.insert(ptr);
					ptr = new node<char>;
					ptr->aptr = new classlist;
					i = 0;
					ptr->aptr->count = 0;
				}
				ptr->aptr->count++;
				stringcopy(ptr->aptr->rollno[i], p);
				stringcopy(ptr->aptr->names[i], q);
				stringcopy(ptr->course, r);
				stringcopy(ptr->sec, s);
			}
            L2.print();
		}
		else
		{
			cout << "File not found. " << endl;
		}
	}
	void printStudentCourses(char roll_no[])
	{
	    node <char>*ptr = new node <char>;
		ptr->aptr = new classlist;
		ifstream fin("dataa.csv");
		if (fin.is_open())
		{
			ptr->aptr->count = 0;
			for (int i = 0; fin.eof() == false; i++)
			{
                fin.getline(ptr->aptr->rollno[i], 10, ',');
                fin.getline(ptr->aptr->names[i], 10, ',');
                fin.getline(ptr->course, 50, ',');
                fin.getline(ptr->sec, 30, '\n');
                ptr->aptr->count++;
				if(stringcompare(ptr->aptr->rollno[i],roll_no)== true)
                {
                    cout<<ptr->course<<endl;
                }
			}
		}
	}
};

int main()
{
	char str[20];
	char dayy[20],timee[10],classrooom[10],temp1[20];
	char secc[20];
	char coursename[60]={"Mass Communication (CS)"};
	//char coursename[60];
	TTADT t;
	t.load(str);
	cout << endl;
	t.loadStudentInfo(str);
	cout << endl;
	cout<<"Write roll no. ";
	cin>>temp1;
	//t.printStudentTimetable(temp1);
	t.printStudentCourses(temp1);
	cout<<endl<<"Enter day ";
	cin>>dayy;
	cout<<"Enter time ";
	cin>>timee;
	cout<<"Enter classroom ";
	cin>>classrooom;
	t.printCourse(dayy,timee,classrooom);
	cout<<endl<<endl;
	/*cout<<"Enter section ";
	cin>>secc;*/
	cout<<coursename<<" timings: "<<endl;
	t.printCourseTimings(coursename);
	t.saveClashes();
	_getch();
}
