#ifndef EX12_27_H
#define EX12_27_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ostream>
#include <memory>
#include <map>
#include <set>

using line_no = std::vector<std::string>::size_type;

class QueryResult;
class TextQuery{
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &ifs) :data(new std::vector<std::string>){
	std::string text;
	while (getline(ifs, text)){
		data->push_back(text);		// save every line
		int n = data->size() - 1;	// line No.
		std::istringstream line(text);	
		std::string word;
		while (line >> word){		
			auto &lines = wm[word];	// lines is a shared_ptr
			if (!lines)				// if it's empty ptr
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f){}
	std::set<line_no>::iterator begin(){
		return lines->cbegin();
	}
	std::set<line_no>::iterator end(){
		return lines->cend();
	}
	std::shared_ptr<std::vector<std::string>> get_file(){
		return file;
	}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;	
	std::shared_ptr<std::vector<std::string>> file; 
};


std::string make_plural(unsigned i, std::string a, std::string b){
	if (i > 1) return (a + b);
	else return a;
}

std::ostream &print(std::ostream &os, const QueryResult &qr){
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		<< *(qr.file->begin() + num) << std::endl;
	return os;
}

QueryResult TextQuery::query(const std::string &sought) const {
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, data);
	else
		return QueryResult(sought, loc->second, data);
}

#endif