#include "ex13_34_36_37.h"

#include <iostream>
using std::cerr; using std::endl;
#include <string>
#include <set>

void Message::save(Folder &f){
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders(){
	for (auto f : folders)
		f->remMsg(this);
}

Message::Message(const Message &m) :
contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message& Message::operator=(const Message &m){
	remove_from_Folders();
	add_to_Folders(m);
	contents = m.contents;
	folders = m.folders;
	return *this;
}

Message::~Message(){
	remove_from_Folders();
}

void swap(Message &lhs, Message &rhs){
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

void Message::debug_print(){
	cerr << contents << " in " << folders.size() << " folders." << endl;
}

void Folder::debug_print(){
	cerr << messages.size() << " messages" << endl;
	for (auto m : messages)
		cerr << "\t" << m->contents << endl;
}

void Folder::add_to_Messages(const Folder &f){
	for (auto m : f.messages)
		m->add_Fldr(this);
}

void Folder::remove_from_Messages(){
	for (auto m : messages)
		m->rem_Fldr(this);
	messages.clear();
}

Folder::Folder(const Folder &f) : messages(f.messages) {
	add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &f){
	remove_from_Messages();
	messages = f.messages;
	add_to_Messages(f);
	return *this;
}

Folder::~Folder(){
	remove_from_Messages();
}