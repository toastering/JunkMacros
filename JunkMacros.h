/*
----------------------------------------------
JunkMacros.h
Created July 2021
Author tostring#1337
----------------------------------------------
*/

#pragma once
#include <Windows.h>

consteval unsigned fshiftrandom()
{
    unsigned short lfsr = __TIME__[7] * 2;
    unsigned bit;

    bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
    return lfsr = (lfsr >> 1) | (bit << 15);
}

void junkcallme() {};
float junkcallme2() { return 3.402823466e+38F + 1; };

constexpr int compiledrand = fshiftrandom() % 100;
constexpr int compiledrand2 = fshiftrandom() % 1337;
constexpr int compiledrandMAX = fshiftrandom() % 2147483647;

template <size_t N>
struct NOPCOMPILE {
    template <size_t I>
    static void gen() {
        __asm nop
        if constexpr (I + 1 < N) NOPCOMPILE<N>::gen<I + 1>();
    }
};

template <size_t N>
struct MOVCOMPILE {
    template <size_t I>
    static void gen() {
        constexpr int yes = fshiftrandom() % 1337;
        __asm { 
            push ah
            mov ah, BYTE PTR yes
            pop ah
        }
        if constexpr (I + 1 < N) MOVCOMPILE<N>::gen<I + 1>();
    }
};

template <size_t N>
struct WINDFUNCSCOMPILE {
    template <size_t I>
    static void gen() {
        rand();
        FindWindowA((char*)(90 + fshiftrandom() % 30),NULL);
        GetCurrentProcessId();
        GetCurrentProcess();
        GetProcessHeap();

        if constexpr (I + 1 < N) WINDFUNCSCOMPILE<N>::gen<I + 1>();
    }
};

template <size_t N>
struct NULLSUBCOMPILE {
    template <size_t I>
    static void gen() {
        __asm call junkcallme

        if constexpr (I + 1 < N) NULLSUBCOMPILE<N>::gen<I + 1>();
    }
};

template <size_t N>
struct IFCOMPILE {
    template <size_t I>
    static void gen() {
        __asm {
            cmp    al, BYTE PTR compiledrand2
            jl     Less
            mov    al, 1
            call junkcallme2
            jl     Less
            call junkcallme
            mov al, BYTE PTR compiledrand2
            dec al
            jmp    Both
            Less :
            mov ah, BYTE PTR CHAR_MAX
            xor ah, al
            jmp Both
            Both :
            inc al
            xor al, BYTE PTR compiledrand
        }

        if constexpr (I + 1 < N) IFCOMPILE<N>::gen<I + 1>();
    }
};

template <size_t N>
struct JMPCOMPILE {
    template <size_t I>
    static void gen() {
        __asm {
            jmp myes
            myes :
        }

        if constexpr (I + 1 < N) JMPCOMPILE<N>::gen<I + 1>();
    }
};

#define NOP_JUNK(am) NOPCOMPILE<((am == 0) ? (fshiftrandom() % 50 + 1) : am)>::gen<0>()

#define MOV_JUNK(am) MOVCOMPILE<((am == 0) ? (fshiftrandom() % 50 + 1) : am)>::gen<0>()

#define WIND_JUNK(am) WINDFUNCSCOMPILE<((am == 0) ? (fshiftrandom() % 20 + 1) : am)>::gen<0>()

#define NULLSUB_JUNK(am) NULLSUBCOMPILE<((am == 0) ? (fshiftrandom() % 60 + 1) : am)>::gen<0>()

#define IF_JUNK(am) IFCOMPILE<((am == 0) ? (fshiftrandom() % 15 + 1) : am)>::gen<0>()

#define JMP_JUNK(am) JMPCOMPILE<((am == 0) ? (fshiftrandom() % 50 + 1) : am)>::gen<0>()
