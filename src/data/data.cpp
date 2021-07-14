//
// Created by Ricardo Santos on 13/07/21.
//

#include "data.h"

std::map<Operation_Name, Operation_Properties> Header_operation_set{
        // Directives
        {"extern", {0, 0}},
        {"begin",  {0, 0}},
        {"public", {0, 0}},
};

std::map<Operation_Name, Operation_Properties> Data_operation_set{
        {"space",  {0, 1}},
        {"const",  {1, 1}},
};

std::map<Operation_Name, Operation_Properties> Text_operation_set{
        // Instructions
        {"add",    {2, 1}},
        {"sub",    {2, 2}},
        {"mul",    {2, 3}},
        {"div",    {2, 4}},
        {"jmp",    {2, 5}},
        {"jmpn",   {2, 6}},
        {"jmpp",   {2, 7}},
        {"jmpz",   {2, 8}},
        {"copy",   {3, 9}},
        {"load",   {2, 10}},
        {"store",  {2, 11}},
        {"input",  {2, 12}},
        {"output", {2, 13}},
        {"stop",   {1, 14}},
        {"end", {0,0}},
};

std::map<int, int> operation_size{
        {1, 2},
        {2, 2},
        {3, 2},
        {4, 2},
        {5, 2},
        {6, 2},
        {7, 2},
        {8, 2},
        {9, 3},
        {10, 2},
        {11, 2},
        {12, 2},
        {13, 2},
        {14, 1},
};