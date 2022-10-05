//
// Created by XIaokang00010 on 2022/10/4.
//

#ifndef ZQHF_OJ_V2_SPJ_BACKEND_SPJ_HPP
#define ZQHF_OJ_V2_SPJ_BACKEND_SPJ_HPP

#include <sstream>

constexpr int8_t wa = 1;

constexpr int8_t ac = 0;

constexpr int8_t syserr = 2;

std::string _A, _B, _T;

std::stringstream ins, outs;

void spj_result(int8_t status, uint32_t score, const std::string &debug_message) {
    std::cout << (int)status << ' ' << (int)score << '\n' << debug_message << std::endl;
    exit(0);
}

void spj_init() {
    std::getline(std::cin, _T);
    if (_T != "------------zqhf-oj-v2-spj-start------------")
        spj_result(syserr, 0, "Unexpected input");
    while (true) {
        std::getline(std::cin, _T);
        if (_T == "------------zqhf-oj-v2-spj-split------------")
            break;
        if (std::cin.eof())
            spj_result(syserr, 0, "Unexpected input");
        _A += _T;
    }
    while (true) {
        std::getline(std::cin, _T);
        if (_T == "------------zqhf-oj-v2-spj-end------------")
            break;
        if (std::cin.eof())
            spj_result(syserr, 0, "Unexpected input");
        _B += _T;
    }
    ins.str(_A);
    outs.str(_B);
}

#endif //ZQHF_OJ_V2_SPJ_BACKEND_SPJ_HPP
