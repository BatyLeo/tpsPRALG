#pragma once

#include "graphe.h"

template<typename Out>
void split(const string &s, char delim, Out result);

vector<string> split(const string &s, char delim);

graphe readInstance(int& A, int& P, int& B, int& K, int& G,vector<vol >& vols);

void writeRes(vector<vector<int> > res);
