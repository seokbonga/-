#pragma once

#ifndef __RECORD_H__
#define __RECORD_H__

#include <cstdio>
#include <cstring>
#include <iomanip>

constexpr int MAX_WORD_LENGTH = 40;
constexpr int MAX_MEANING_LENGTH = 200;

using namespace std;

class Record {
public:
	Record(const char* word = "", const char* meaning = "") { set(word, meaning); }

	void	set(const char* word, const char* meaning);
	int		compare(const Record* other);
	int		compare(const char* word);
	void	copy(const Record* other) { set(other->word, other->meaning); }
	void	display() { printf(" %12s : %-40s\n", word, meaning);}
	char*	getWord() { return word; }
	char*	getMeaning() { return meaning; }
private:
	char	word[MAX_WORD_LENGTH];
	char	meaning[MAX_MEANING_LENGTH];
};

void Record::set(const char* word, const char* meaning)
{
	strcpy_s(this->word, MAX_WORD_LENGTH, word);
	strcpy_s(this->meaning, MAX_MEANING_LENGTH, meaning);
}

int Record::compare(const Record* other)	//문장비교
{
	return compare(other->word);
}

int Record::compare(const char* word)	//overloading
{
	return strcmp(this->word, word);
	/*
		사전순으로 단어 저장
	*/
}
#endif