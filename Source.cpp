#include <iostream>
#include <fstream>
using namespace std;



class object;

class date {

private:
	int day;
	int month;
	int year;
	

public:
	
	int get_day() {
		return day;
	}

	int get_month() {
		return month;
	}

	int get_year() {
		return year;
	}
	date(int d = 0, int m = 0, int y = 0) {
		day = d;
		month = m;
		year = y;
	}

	void set(int d = 0, int m = 0, int y = 0) {
		day = d;
		month = m;
		year = y;
	}

	void print_date() {
		cout << " (" << day << "/" << month << "/" << year << ")" << endl;
	}

	
};

date current_date;

class helper {
public:
	static void mystrcpy(char*& a, char* b) {

		int i = 0;
		for (;b[i] != '\0';i++) {
			a[i] = b[i];
		}
		a[i] = '\0';
	}

	static char* extract_like_post(char* b) {
		int len = strlen(b), t = 0;
		if (len >= 10) {
			for (int i = 5;b[i] != '\0';i++) {
				t++;
			}
			char* a = new char[t+1];
			int x = 0;
			for (int i = 5;i < len;i++) {
				a[x] = b[i];
				x++;
			}
			a[x] = '\0';
			return a;
		}
		else {
			return nullptr;
		}
	}

	static char* liked_list(char* b) {
		int len = strlen(b), t = 0;
		if (len >= 16) {
			for (int i = 16;b[i] != ')';i++) {
				t++;
			}
			char* a = new char[t+1];
			int x = 0;
			for (int i = 16;b[i] != ')';i++) {
				a[x] = b[i];
				x++;
			}
			a[x] = '\0';
			return a;
		}
		else {
			return nullptr;
		}
	}

	static void system_date(char* b, int& a, int& c, int& d) {
		int i = 24;
		while (b[i] != '\0') {

			while (b[i] != ' ' && b[i] != '\0') {
				int k = b[i] - '0';
				a = a * 10 + k;
				i++;
			}
			i++;
			while (b[i] != ' ' && b[i] != '\0') {
				int k = b[i] - '0';
				c = c * 10 + k;
				i++;
			}
			i++;
			while (b[i] != ' ' && b[i] != '\0') {
				int k = b[i] - '0';
				d = d * 10 + k;
				i++;
			}

		}

	}
	 
	static bool date_com(date a, date b) {
		if (a.get_year() == b.get_year()) {

			if (a.get_month() == b.get_month()) {

				if (a.get_day() == b.get_day() || a.get_day()-1 == b.get_day() || a.get_day()-2 == b.get_day() || a.get_day() - 3 == b.get_day()) {
					return true;
				}
				else {
					return false;
				}

			}
			else {
				return false;
			}

		}
		else {
			return false;
		}
	}

	static char* extract_page(char* b) {
		int len = strlen(b), t = 0;
		if (len >= 7) {
			for (int i = 5;b[i] != '\0';i++) {
				t++;
			}
			char* a = new char[t+1];
			int x = 0;
			for (int i = 5;i < len;i++) {
				a[x] = b[i];
				x++;
			}
			a[x] = '\0';
			return a;
		}
		else {
			return nullptr;
		}
	}
	static char* extract_user(char* b) {
		int len = strlen(b), t = 0;
		if (len >= 19) {
			for (int i = 17;b[i] != '\0';i++) {
				t++;
			}
			char* a = new char[t+1];
			int x = 0;
			for (int i = 17;i < len;i++) {
				a[x] = b[i];
				x++;
			}
			a[x] = '\0';
			return a;
		}
		else {
			return nullptr;
		}
	}

	static char* extract_post_comment(char* b) {
		if (strlen(b) > 18) {
			if (b != nullptr) {
				int t = 0;
				for (int i = 13;b[i] != ',';i++) {
					t++;
				}
				char* a = new char[t + 1];

				int i = 13, track = 0;

				for (;b[i] != ',';i++) {
					a[track] = b[i];
					track++;
				}
				a[track] = '\0';
				return a;
			}
			else {
				return nullptr;
			}
		}
		else {
			return nullptr;
		}
	}

	static char* extract_comment_text(char* b) {
		if (strlen(b) > 18) {
			if (b != nullptr) {
				int t = 0, stop = 0, index = 0;
				for (int i = 0;b[i] != ')';i++) {
					if (b[i] == ',') {
						stop = 1;
						index = i + 1;
					}
					if (stop == 1) {
						t++;
					}
				}
				char* a = new char[t + 1];

				int i = index, track = 0;

				for (;b[i] != ')';i++) {
					a[track] = b[i];
					track++;
				}
				a[track] = '\0';
				return a;
			}
			else {
				return nullptr;
			}
		}
		else {
			return nullptr;
		}
	}

	static char* extract_post(char* b) {
		int len = strlen(b), t = 0;
		if (len >= 16) {
			for (int i = 10;b[i] != '\0';i++) {
				t++;
			}
			char* a = new char[t+1];
			int x = 0;
			for (int i = 10;i < len-1;i++) {
				a[x] = b[i];
				x++;
			}
			a[x] = '\0';
			return a;
		}
		else {
			return nullptr;
		}


	}

	static bool verify_memory(date a) {
		if ((a.get_day() == current_date.get_day()) && (a.get_month() == current_date.get_month()) && (a.get_year()!=current_date.get_year())) {
			return true;
		}
		else {
			return false;
		}
	}

	static int count_years(date a,int& b) {
		int i = 1, stop = 0;
		for (;stop == 0;i++) {
			if (current_date.get_year() - i == a.get_year()) {
				stop = 1;
				b = i;
			}
		}
		return b;
	}

	static void extract_post_text(char*& a, char*& b,char*c) {
		int i = 13,t=0;
		while (c[i] != ',') {
			t++;
			i++;
		}
		a = new char[t+1];
		i = 13, t = 0;
		while (c[i] != ',') {
			a[t] = c[i];
			t++;
			i++;
		}
		a[t] = '\0';
		i++;
		t = 0;
		int d = i;
		while (c[i] != '\0') {
			t++;
			i++;
		}
		b = new char[t+1];
		t = 0;
		while (c[d] != '\0') {
			b[t] = c[d];
			t++;
			d++;
			i++;
		}
		b[t] = '\0';
	}
};


class Comments {

private:
	char* id;
	object* commented_by;
	char* text;


public:
	Comments() {
		commented_by = nullptr;
		text = nullptr;
		id = nullptr;
	}

	~Comments() {
		if (id != nullptr) {
			delete[]id;
		}
		if (text != nullptr) {
			delete[]text;
		}
	}

	void set_text(char* b) {
		if (b != nullptr) {
			text = new char[strlen(b)+1];
			helper::mystrcpy(text, b);
		}
	}

	void set_commented_by(object* a) {
		if (commented_by == nullptr) {
			commented_by = a;
		}

	}

	void set_id(char* b) {
		if (b != nullptr) {
			int size = strlen(b) + 1;
			id = new char[size];
			helper::mystrcpy(id, b);
		}
	}

	char* get_text() {
		return text;
	}

	char* get_id() {
		return id;
	}

	object* get_commented_by() {
		return commented_by;
	}
};


class post_content {
public:
	virtual void print_all() = 0;

	virtual ~post_content() {
	}
};


class activity : public post_content {

private:
	int type;
	char* value;
	char* affiliaton;
public:
	activity() {
		type = 0;
		value = nullptr;
		affiliaton = nullptr;
	}

	~activity() {
		if (value != nullptr) {
			delete[] value;
		}
		if (affiliaton != nullptr) {
			delete[] affiliaton;
		}
	}

	void input(ifstream& ain) {
		ain >> type;
		if (type == 1) {
			char a[100] = { "feeling" };
			affiliaton = new char[strlen(a) + 1];
			helper::mystrcpy(affiliaton, a);
		}
		else if (type == 2) {
			char a[20] = { "thinking about" };
			affiliaton = new char[strlen(a) + 1];
			helper::mystrcpy(affiliaton, a);
		}
		else if (type == 3) {
			char a[20] = { "making" };
			affiliaton = new char[strlen(a) + 1];
			helper::mystrcpy(affiliaton, a);
		}
		else if (type == 4) {
			char a[20] = { "celebating" };
			affiliaton = new char[strlen(a) + 1];
			helper::mystrcpy(affiliaton, a);
		}
		char b[100];
		ain.ignore();
		ain.getline(b, 100);
		value = new char[strlen(b) + 1];
		helper::mystrcpy(value, b);
	}

	void print_all() {
		cout << " is " << affiliaton << " " << value<<" ";
	}
};


class post;


class object {

protected:
	char* id;
	post** timeline;

public:
	object() {
		id = nullptr;
		timeline = nullptr;
	}

	virtual ~object();

	char* gett_id() {
		return id;
	}

	void print_memory();
	virtual void print_latest_post();
	virtual void add_timeline(post*& a) {
			if (timeline == nullptr) {
				timeline = new post * [10];
				for (int i = 0;i < 10;i++) {
					timeline[i] = nullptr;
				}
			}

			for (int i = 0;i < 10;i++) {
				if (timeline[i] == nullptr) {
					timeline[i] = a;
					break;
				}
			}
		
	}
	virtual char* get_name() = 0;
	virtual void view_timeline();
	bool post_found(post* p);
};


class post {

private:
	char* id;
	char* text;
	object* shared_by;
	object** liked_by;
	date shared_date;
	Comments** comments;
	post_content* content;

public:
	post() {
		id = nullptr;
		text = nullptr;
		shared_by = nullptr;
		liked_by = nullptr;
		comments = nullptr;
		content = nullptr;
	}

	virtual ~post() {
		if (id != nullptr) {
			delete[]id;
		}
		if (text != nullptr) {
			delete[] text;
		}
		if (liked_by != nullptr) {
			delete[]liked_by;
		}
		if (comments != nullptr) {
			for (int i = 0;comments[i] != nullptr;i++) {
				delete[]comments[i];
			}
			delete[] comments;
		}
		if (content != nullptr) {
			delete[]content;
		}

	}

	post(char* a, object* shar_by, date d) {
		if (a != nullptr) {
			text = new char[strlen(a) + 1];
			helper::mystrcpy(text, a);
		}
		if (shar_by != nullptr) {
			shared_by = shar_by;
		}
		shared_date = d;
	}

	void print_time() {
		if (current_date.get_year() == shared_date.get_year() && current_date.get_month() == shared_date.get_month())
		{
			if (current_date.get_day() == shared_date.get_day()) {
				cout << " (1h)" << endl;

			}
			else if (current_date.get_day() - 1 == shared_date.get_day()) {
				cout << " (1d)" << endl;
			}
			else if (current_date.get_day() - 2 == shared_date.get_day()) {
				cout << " (2d)" << endl;
			}
			else if (current_date.get_day() - 3 == shared_date.get_day()) {
				cout << " (3d)" << endl;
			}
			else {
				cout << " (" << shared_date.get_day() << "/" << shared_date.get_month() << "/" << shared_date.get_year() << ")" << endl;
			}
		}
		else {
			cout << " (" << shared_date.get_day() << "/" << shared_date.get_month() << "/" << shared_date.get_year() << ")" << endl;
		}
	}

	void add_comments(Comments* a) {
		if (comments == nullptr) {
			comments = new Comments * [10];
			for (int i = 0;i < 10;i++) {
				comments[i] = nullptr;
			}
		}

		for (int i = 0;i < 10;i++) {
			if (comments[i] == nullptr) {
				comments[i] = a;
				break;
			}
		}
	}

	void add_post_content(post_content* a) {
		if (content == nullptr) {
			content = a;
		}
	}

	void print() {
		if (content != nullptr) {
			content->print_all();
		}
		cout << " ";
		shared_date.print_date();
		cout << endl << endl;
		cout << "                          " << "'" << text << "'" << endl << endl;
		if (comments != nullptr) {
			for (int i = 0;i < 10;i++) {
				if (comments[i] != nullptr) {
					object* o = comments[i]->get_commented_by();

					if (o != nullptr) {
						cout <<"                                   "<< o->get_name() << ": " << comments[i]->get_text() << endl;
					}
				}
			}
		}
		else {
			cout << "No comments " << endl;
		}
		cout << endl;
	}

	virtual void print_all() {
		cout << "---" << shared_by->get_name() << " ";
		print_activity();
		print_time();
		print_cotent();
	}

	void print_activity() {
		if (content != nullptr) {
			content->print_all();
		}
	}

	void print_cotent() {
		cout <<endl<< "                     " << "'" << text << "'" << endl << endl;
		if (comments != nullptr) {
			for (int i = 0;i < 10;i++) {
				if (comments[i] != nullptr) {
					object* o = comments[i]->get_commented_by();

					if (o != nullptr) {
						cout << "                          " << o->get_name() << ": " << comments[i]->get_text() << endl;
					}
				}
			}
		}
		else {
			cout << "                          No comments " << endl;
		}
		cout << endl;
	}

	void print_liked_by() {
		if (liked_by != nullptr) {
			cout << endl << "                                    Post liked by :" << endl << endl;
			for (int i = 0;i < 10;i++) {
				if (liked_by[i] != nullptr) {
					cout <<"                                    "<< liked_by[i]->gett_id() << " - " << liked_by[i]->get_name() << endl;
				}
				else {
					break;
				}
			}
		}
		else {
			cout << "                                     No like" << endl;
		}
	}

	char* get_id() {
		return id;
	}

	date get_date() {
		return shared_date;
	}

	void input(ifstream& postin) {

		char a[20];

		postin.getline(a, 20);
		id = new char[strlen(a) + 1];
		helper::mystrcpy(id, a);

		int e, b, c;
		postin >> e;
		postin >> b;
		postin >> c;
		shared_date.set(e, b, c);
		postin.ignore();
		char d[100];
		postin.getline(d, 100);
		text = new char[strlen(d) + 1];
		helper::mystrcpy(text, d);

	}

	void add_shared_by(object*& a) {
		shared_by = a;
	}

	void add_liked_by(object*& a) {
		if (liked_by == nullptr) {
			liked_by = new object * [10];
			for (int i = 0;i < 10;i++) {
				liked_by[i] = nullptr;
			}
		}

		int stop = 0;
		for (int i = 0;i < 10 && stop == 0;i++) {
			if (liked_by[i] == nullptr) {
				if (stop == 0) {
					liked_by[i] = a;
					stop = 1;
				}
			}
		}
		if (stop == 0) {
			cout << "This user has already liked 10 posts." << endl;
		}
	}

	void print_text() {
		cout << text;
	}

	void print_name() {
		cout << shared_by->get_name()<<" ";
	}

	char* get_text() {
		return text;
	}

	void print_shared_date() {
		shared_date.print_date();
	}

	virtual void print_name_id() {

	}


};


void object::view_timeline() {
	if (timeline != nullptr) {
		for (int i = 0;i < 10;i++) {
			if (timeline[i] != nullptr) {
				timeline[i]->print_all();
			}
			else {
				break;
			}
		}
	}
	else {
		cout << "No preview available" << endl;
	}
}

void object::print_latest_post() {

	if (timeline != nullptr) {
		for (int i = 0;timeline[i] != nullptr;i++) {

			date b = timeline[i]->get_date();
			if (helper::date_com(current_date, b) == true) {
				cout << "---" << get_name() << " ";
				timeline[i]->print_activity();
				timeline[i]->print_time();
				timeline[i]->print_cotent();
			}
				
		}
	}
}

void object::print_memory() {
	int count = 0,stop=0;
	if (timeline != nullptr) {
		for (int i = 0;timeline[i] != nullptr;i++) {
			if (helper::verify_memory(timeline[i]->get_date()) == true) {
				cout << "On this day " << endl;
				int years = 0;
				helper::count_years(timeline[i]->get_date(), years);
				cout << years << " Years Ago" << endl;
				cout << "---" << get_name() << " ";
				timeline[i]->print_activity();
				timeline[i]->print_time();
				timeline[i]->print_cotent();
				stop = 1;
			}
		}
		if (stop == 0) {
			cout << "No Memories available" << endl;
		}

	}
	else {
		cout << "No Memories" << endl;
	}
}

object:: ~object() {
	if (id != nullptr) {
		delete[] id;
	}
	if (timeline != nullptr) {
		for (int i = 0;timeline[i] != nullptr;i++) {
			if (timeline[i] != nullptr) {
				delete[] timeline[i];
			}
		}
		delete[]timeline;
	}

}

bool object::post_found(post* p) {

	if (timeline != nullptr) {

		for (int j = 0;timeline[j]!=nullptr; j++) {
			if (strcmp(timeline[j]->get_id(), p->get_id()) == 0) {
				return true;
			}
		}
		return false;
	}
	else {
		return false;
	}
}



class memory : public post {

private:
	post* org_post;

public:
	memory(char* a, post* p, object* shar_by) : post(a, shar_by, current_date) {
		org_post = p;
	}

	~memory() {
	    
	}

	void print_all() {
		org_post->print_name();
		cout << "shared a memory " ;
		post::print_time();
		cout << "'" << post::get_text() << "'" << endl;
		int years = 0;
		helper::count_years(org_post->get_date(), years);
		cout << "      ~~~ " << years << " years ago ~~~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		org_post->print_cotent();
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
};


class Pages : public object {

private:
	char* name;

public:
	Pages() {
		name = nullptr;
	}

	~Pages() {
		if (name != nullptr) {
			delete[] name;
		}
	}
	
	void Input(ifstream& pin) {

		char* temp_id = new char[10];
		pin.getline(temp_id, 10);
		id = new char[strlen(temp_id) + 1];
		helper::mystrcpy(id, temp_id);




		char* temp_name = new char[50];
		pin.getline(temp_name, 50);


		name = new char[strlen(temp_name) + 1];
		helper::mystrcpy(name, temp_name);

		delete[] temp_id;
		delete[] temp_name;
	}

	char* get_name() {
		return name;
	}
	void print_latest_post() {
		object::print_latest_post();
	}
	void add_timeline(post*& a) {
		object::add_timeline(a);
	}
	void print_name_id() {
		cout <<"                           "<< id << " - " << name << endl;

	}
	void view_timeline() {
		cout << endl << get_name() << " -- Timeline :" << endl << endl;
		object::view_timeline();
	}

};


class User : public object {
private:
	char* name;
	User** friends;
	Pages** likedpages;

public:
	User() {
		name = nullptr;
		friends = nullptr;
		likedpages = nullptr;
	}
	
	~User() {
		
		if (name != nullptr) {
			delete[] name;
		}
		if (friends != nullptr) {
			delete[]friends;
		}
		if (likedpages != nullptr) {
			delete[] likedpages;
		}
	}

	void Input(ifstream& uin) {

		char* temp_id = new char[10];
		uin.getline(temp_id, 10);
		id = new char[strlen(temp_id) + 1];
		helper::mystrcpy(id, temp_id);




		char* temp_name = new char[50];
		uin.getline(temp_name, 50);


		name = new char[strlen(temp_name) + 1];
		helper::mystrcpy(name, temp_name);

		delete[] temp_id;
		delete[] temp_name;
	}

	char* get_name() {
		return name;
	}

	void print_latest_post() {
		object::print_latest_post();
	}

	void addfriend(User*& a) {

		if (friends == nullptr) {
			friends = new User * [10];
			for (int i = 0;i < 10;i++) {
				friends[i] = nullptr;
			}
		}

		int stop = 0;
		for (int i = 0;i < 10 && stop == 0;i++) {
			if (friends[i] == nullptr) {
				friends[i] = a;
				stop = 1;
			}
		}
	}

	void likepage(Pages*& a) {

		if (likedpages == nullptr) {
			likedpages = new Pages * [10];
			for (int i = 0;i < 10;i++) {
				likedpages[i] = nullptr;
			}
		}

		int stop = 0;
		for (int i = 0;i < 10 && stop == 0;i++) {
			if (likedpages[i] == nullptr) {
				likedpages[i] = a;
				stop = 1;
			}
		}
	}

	void view_home() {
		cout << name << " - Home Page" << endl << endl;
		if (friends != nullptr) {
			
			for (int i = 0;friends[i] != nullptr;i++) {
				
					friends[i]->print_latest_post();
				
			}

		}
		
		if (likedpages != nullptr) {
			for (int i = 0;likedpages[i] != nullptr;i++) {
				
					likedpages[i]->print_latest_post();
				
			}
		}

		else {
			cout << "No HOME AVAILABLE" << endl;
		}
	}

	void print_f() {
		if (friends != nullptr) {
			for (int i = 0;i < 10;i++) {
				if (friends[i] != 0) {
					cout << friends[i]->gett_id() << "---" << friends[i]->name << endl;
				}
			}
		}
		else {
			cout << "No Friends" << endl;
		}
		
	}

	void print_p() {
		if (likedpages != nullptr) {
			for (int i = 0;i < 10;i++) {
				if (likedpages[i] != 0) {
					cout << likedpages[i]->gett_id() << "---" << likedpages[i]->get_name() << endl;
				}
			}
		}
		else {
			cout << "NO liked Pages" << endl;
		}
		
	}

	void print_name_id() {
		cout << "                           "<<id << " - " << name << endl;

	}

	void add_timeline(post*& a) {
		object::add_timeline(a);
	}

	void view_timeline() {
		cout << endl << get_name() << " -- Timeline :" << endl << endl;
		object::view_timeline();
	}

	
};


class controller {

private:
	User** All_User;
	Pages** All_Pages;
	post** All_posts;
	Comments** All_comments;
	activity** All_activities;
    
public:
	controller() {
		All_User = nullptr;
		All_Pages = nullptr;
		All_posts = nullptr;
		All_activities = nullptr;
	}

	~controller() {
		if (All_User != nullptr) {
			delete[] All_User;
		}
		if (All_Pages != nullptr) {
			delete[] All_Pages;
		}
		if (All_posts != nullptr) {
			delete[] All_posts;
		}
		if (All_comments != nullptr) {
			delete[] All_comments;
		}
		if (All_activities != nullptr) {
			delete[] All_activities;
		}
	}

	void unload_users() {
		if (All_User != nullptr) {
			for (int i = 0;i < 20;i++) {
				delete[] All_User[i];
			}
		}
	}

	void unload_pages() {
		if (All_Pages != nullptr) {
			for (int i = 0;i < 12;i++) {
				delete[] All_Pages[i];
			}
		}
	}

	void load_users(ifstream& uin) {

		int size;
		uin >> size;
		All_User = new User * [size];
		uin.ignore();

		for (int i = 0;i < size;i++) {
			All_User[i] = new User[1];
			All_User[i]->Input(uin);
		}

	}

	void load_pages(ifstream& pin) {

		int sizep;
		pin >> sizep;
		All_Pages = new Pages * [sizep];
		pin.ignore();

		for (int i = 0;i < sizep;i++) {
			All_Pages[i] = new Pages[1];
			All_Pages[i]->Input(pin);
		}
	}

	User* search_by_id(char* a) {

		int i = 0, stop = 0;
		for (;i < 20 && stop == 0;i++) {
			if (strcmp(All_User[i]->gett_id(), a) == 0) {
				stop = 1;
				i--;
			}
		}
		if (stop == 1) {
			return All_User[i];
		}
		else {
			return nullptr;
		}
		
	}

	post* post_by_id(char* a) {
		int i = 0, stop = 0;
		for (;i < 12 && stop == 0;i++) {
			if (strcmp(All_posts[i]->get_id(), a) == 0) {
				stop = 1;
				i--;
			}
		}
		if (stop == 1) {
			return All_posts[i];
		}
		else {
			return nullptr;
		}
		
	}

	Pages* page_by_id(char* a) {

		int i = 0, stop = 0;
		for (;i < 12 && stop == 0;i++) {
			if (strcmp(All_Pages[i]->gett_id(), a) == 0) {
				stop = 1;
				i--;
			}
		}
		if (stop == 1) {
			return All_Pages[i];
		}
		else {
			return nullptr;
		}
		
	}

	User* search_by_id(User* a) {
		for (int i = 0;i < 20;i++) {
			if (strcmp(All_User[i]->gett_id(), a->gett_id()) == 0) {
				return All_User[i];
			}
		}
		return nullptr;
	}

	Pages* page_by_id(Pages* a) {
		for (int i = 0;i < 12;i++) {
			if (strcmp(All_Pages[i]->gett_id(), a->gett_id()) == 0) {
				return All_Pages[i];
			}
		}
		return nullptr;
	}

	post* post_by_id(post* a) {
		for (int i = 0;i < 12;i++) {
			if (strcmp(All_posts[i]->get_id(), a->get_id()) == 0) {
				return All_posts[i];
			}
		}
		return nullptr;
	}

	object* obj_by_id(char* a) {
		object* o = page_by_id(a);
		if (o == nullptr) {
			o = search_by_id(a);
		}
		return o;
	
	}

	void load_activities(ifstream& ain) {

		int size;
		ain >> size;
		All_activities = new activity*[size];
		ain.ignore();
		for (int i = 0;i < size;i++) {
			All_activities[i] = new activity[1];
			char a[10];
			ain.getline(a, 20);
			post* p = post_by_id(a);
			All_activities[i]->input(ain);
			if (p != nullptr) {
				p->add_post_content(All_activities[i]);
			}
		}


	}

	void load_user_profile(ifstream& fin) {

		char temp[20];
		fin.getline(temp, 20);

		while (strcmp(temp, "-1") == 1) {

			User* org = search_by_id(temp);
			fin.getline(temp, 20);
			while (strcmp(temp, "-1") == 1) {
				User* ref = search_by_id(temp);
				org->addfriend(ref);
				fin.getline(temp, 20);
			}
			fin.getline(temp, 20);
			while (strcmp(temp, "-1") == 1) {
				Pages* ref = page_by_id(temp);
				org->likepage(ref);
				fin.getline(temp, 20);
			}
			fin.getline(temp, 20);
		}

	}


	void load_timeline(ifstream& postin) {

		int size;
		postin >> size;
		All_posts = new post * [size];
		postin.ignore();
		for (int i = 0;i < size;i++) {
			All_posts[i] = new post[1];
			All_posts[i]->input(postin);
			char temp[10];
			postin.getline(temp, 20);
			int j = 0;
			while (strcmp(temp, "-1") == 1) {
				object* copy ;
				User* ref = search_by_id(temp);
				if (ref != nullptr) {
					copy = ref;
					if (j == 0) {
						All_posts[i]->add_shared_by(copy);
						ref->add_timeline(All_posts[i]);
					}
					else {
						All_posts[i]->add_liked_by(copy);
					}
				}
				else {
					Pages* reff = page_by_id(temp);
					if (reff != nullptr) {
						copy = reff;
						if (j == 0) {
							All_posts[i]->add_shared_by(copy);
							reff->add_timeline(All_posts[i]);
						}
						else {
							All_posts[i]->add_liked_by(copy);
						}
					}

				}
				j++;
				postin.getline(temp, 20);
			}
		}


	}

	void printname(User* a) {

		if (a != nullptr) {
			User* u = search_by_id(a);
			if (u != nullptr) {
				cout << u->get_name() << " successfully set as Current User" << endl;
			}
			else {
				cout << "No User Found." << endl;
			}
		}
		else {
			cout << "Invalid command" << endl;
		}

		
	}


	void printfriends(User* a) {

		if (a != nullptr) {
			User* u = search_by_id(a);
			if (u != nullptr) {
				u->print_f();
			}
			else {
				cout << "No User Found." << endl;
			}
		}
		else {
			cout << "Invalid command" << endl;
		}
	}

	void printpages(User* a) {
		if (a != nullptr) {
			User* u = search_by_id(a);
			if (u != nullptr) {
				u->print_p();
			}
			else {
				cout << "No User Found." << endl;
			}
		}
		else {
			cout << "Invalid command" << endl;
		}
	}

	void print_user_timeline(User* a) {
		if (a != nullptr) {
			User* u = search_by_id(a);
			if (u != nullptr) {
				u->view_timeline();
			}
			else {
				cout << "No User Found." << endl;
			}
		}
		else {
			cout << "Invalid command" << endl;
		}
	}

	void print_page_timeline(Pages* a) {
		if (a != nullptr) {
			Pages* u = page_by_id(a);
			if (u != nullptr) {
				u->view_timeline();
			}
			else {
				cout << "No User Found." << endl;
			}
		}
		else {
			cout << "Invalid command" << endl;
		}
	}

	void print_post_liked(post* a) {
		if (a != nullptr) {
			post* p = post_by_id(a);
			if (a != nullptr) {
				p->print_liked_by();
			}
			else {
				cout << "No Post found" << endl;
			}
		}
		else {
			cout << "No Post found" << endl;
		}
	}


	void load_comments(ifstream& comm) {
		object* o = nullptr;
		int total;
		comm >> total;
		All_comments = new Comments * [total];
		comm.ignore();
		comm.ignore();
		for (int i = 0;i < total;i++) {
			All_comments[i] = new Comments[1];
			char a[80];
			comm.getline(a, 80);
			All_comments[i]->set_id(a);
			comm.getline(a, 80);
			post* p = post_by_id(a);
			p->add_comments(All_comments[i]);
			comm.getline(a, 80);
			o = search_by_id(a);
			if (o == nullptr) {
				o = page_by_id(a);
			}
			All_comments[i]->set_commented_by(o);
			comm.getline(a, 80);
			All_comments[i]->set_text(a);
		}

	}


	void view_post(post* a) {
		if (a != nullptr) {
			post* p = post_by_id(a);
			if (p != nullptr) {
				cout << endl << "---";
				p->print_name();
				p->print_time();
				cout << endl;
				p->print_cotent();
				p->print_liked_by();
			}
			else {
				cout << "No Post found" << endl;
			}
		}
		else {
			cout << "No Post found" << endl;
		}
	}

	void load_data() {
		ifstream uin("User.txt");
		ifstream pin("Pages.txt");
		ifstream fin("User profile.txt");
		ifstream postin("Post.txt");
		ifstream comm("Comments.txt");
		ifstream ain("Activities.txt");

		if (!pin) {
			cout << "Niakl" << endl;
		}

		load_users(uin);
		load_pages(pin);
		load_user_profile(fin);
		load_timeline(postin);
		load_comments(comm);
		load_activities(ain);
	}

	void app() {


		
		object* o = nullptr;
		User* c = nullptr;
		Pages* p = nullptr;
		post* pst = nullptr;

		char a[100] = "Set current system date 17 4 2024";
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Command: Set current system date 17 4 2024" << endl;
		cout << "-----------------------------------------------------------------------" << endl;

		int day = 0, month = 0, year = 0;
		helper::system_date(a, day, month, year);
		current_date.set(day, month, year);
		cout << "System Date :";
		current_date.print_date();


		
		char b[100] = "set current user u7";
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Command: set current user u7" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		c = search_by_id(helper::extract_user(b));
		if (c != nullptr) {
			printname(c);
		}
		else {
			cout << "No user found !!" << endl;
		}




		cout << "-----------------------------------------------------------------------" << endl;
		char z[100] = "view friend list";
		cout << "Command: view friend list" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		   if (c != nullptr) {
			   printfriends(c);
		   }
		   else {
			   cout << "No current user set" << endl;
		   }

	
	
		   char d[100] = "view liked pages";
		   cout << "-----------------------------------------------------------------------" << endl;
		   cout << "Command: view liked pages" << endl;
		   cout << "-----------------------------------------------------------------------" << endl;
		   if (c != nullptr) {
			   printpages(c);
		   }
		   else {
			   cout << "No current user set" << endl;
		   }

		   cout << "-----------------------------------------------------------------------" << endl;
		   char e[100] = "view Timeline";
		   cout << "-----------------------------------------------------------------------" << endl;
		   cout << "Command: view Timeline" << endl;
		   if (c != nullptr) {
			   print_user_timeline(c);
		   }
		   else {
			   cout << "No current user set" << endl;
		   }




		   char f[100] = "like post5";
		   cout << "-----------------------------------------------------------------------" << endl;
		   cout << "Command: like post5" << endl;
		   cout << "-----------------------------------------------------------------------" << endl;
		   pst = nullptr;
		   if (c != nullptr) {
			   o = c;
		   }
		   else {
			   o = p;
		   }
		   post* po = post_by_id(helper::extract_like_post(f));
		   po->add_liked_by(o);
		   cout << o->gett_id() << " has liked " << po->get_id() << "." << endl;


		   char v[100] = "view liked list(post5)";
		   cout << "-----------------------------------------------------------------------" << endl;
		   cout << "Command: view liked list(post5)" << endl;
		   cout << "-----------------------------------------------------------------------" << endl;
		   print_post_liked(post_by_id(helper::liked_list(v)));



		char g[100] = "view p1";
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "Command: view p1" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		
			p = page_by_id(helper::extract_page(g));
			if (p != nullptr) {
				print_page_timeline(p);
			}
			else {
				pst = post_by_id(helper::extract_page(b));
				view_post(pst);
			}
		


			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: view home" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			const char h[100] = "view home";

			if (c != nullptr) {
				c->view_home();
			}
			else {
				cout << "No current user set" << endl;
			}



			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: Post Comment(post4, Good Luck for your Result)" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
		     char i[100] = "Post Comment(post4, Good Luck for your Result)";
			if (c != nullptr) {
				o = c;
				char* c = helper::extract_post_comment(i);
				post* p = post_by_id(c);
				char* comm = helper::extract_comment_text(i);
				Comments* comment = new Comments[1];
				comment->set_commented_by(o);
				comment->set_text(comm);
				p->add_comments(comment);
				cout << "successfully commented" << endl;
			}
			else {
				cout << "No current user set" << endl;
			}


			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: view post(post4)" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			char j[100] = "view post(post4)";
			pst = post_by_id(helper::extract_post(j));
			if (pst != nullptr) {
				view_post(pst);
			}
			else {
				cout << "No Post found !!" << endl;
			}



			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command:  Post Comment(post8, Thanks for the wishes)" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			 char k[100] = "Post Comment(post8, Thanks for the wishes)";
			if (c != nullptr) {
				o = c;
				char* c = helper::extract_post_comment(k);
				post* p = post_by_id(c);
				char* comm = helper::extract_comment_text(k);
				Comments* comment = new Comments[1];
				comment->set_commented_by(o);
				comment->set_text(comm);
				p->add_comments(comment);
				cout << "successfully commented" << endl;
			}
			else {
				cout << "No current user set" << endl;
			}




			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: view post(post8)" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			 char l[100] = "view post(post8)";

			pst = post_by_id(helper::extract_post(l));
			if (pst != nullptr) {
				view_post(pst);
			}
			else {
				cout << "No Post found !!" << endl;
			}




			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: see your memories" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			const char m[100] = "see your memories";

			if (c != nullptr) {
				o = c;
			}
			else {
				o = p;
			}
			o->print_memory();

			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: share memory(post10,Never thought I will be specialist in this field…)" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			 char n[100] = "share memory(post10,Never thought I will be specialist in this field…)";

			if (c != nullptr) {
				o = c;
			}
			else {
				o = p;
			}
			char* postt;
			char* text;
			helper::extract_post_text(postt, text, n);
			post* pos = post_by_id(postt);
			if (pos != nullptr) {
				
				if (o->post_found(pos) == true) {
					memory* memPtr = new memory(text, pos, o);
					post* temp = memPtr;
					o->add_timeline(temp);
					cout << "Succesfully shared" << endl;
				}
				else {
					cout << "Failed !!   " <<  pos->get_id() << " is not the memory of current user" << endl;
				}
			}
			else {
				cout << "No memories found" << endl;
			}


		
			
			char x[100] = "view Timeline";
			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: view Timeline" << endl;
			cout << "-----------------------------------------------------------------------" << endl;
			if (c != nullptr) {
				print_user_timeline(c);
			}
			else {
				cout << "No current user set" << endl;
			}

			char q[100] = "Set current user u11";
			cout << "-----------------------------------------------------------------------" << endl;
			cout << "Command: Set current user u11" << endl;
			cout << "-----------------------------------------------------------------------" << endl;

			c = search_by_id(helper::extract_user(q));
			if (c != nullptr) {
				printname(c);
			}
			else {
				cout << "No user found !!" << endl;
			}

			unload_users();
			unload_pages();

	}

	
};


int main() {

	controller a;
	a.load_data();
	a.app();
	
	return 0;
}