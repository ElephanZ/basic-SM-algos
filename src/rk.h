#pragma once

void rabinKarp_preprocessing(const string P, const string T, const uint M, uint &hash, uint &t_hash, uint &p_hash)
{
   for (uint i = 1; i < M; i++, hash <<= 1);
   for (uint i = 0; i < M; i++)
      p_hash = ((p_hash << 1) + (uint)P[i]),
      t_hash = ((t_hash << 1) + (uint)T[i]);
}

uint rabinKarp(const string T, const uint N, const string P, const uint M)
{
   uint h = 1, hp = 0, ht = 0, cnt = 0;

   auto t_rehash = [&](const uint s) { return ((ht - T[s]*h) << 1) + T[M + s]; };
   auto check = [=](const uint s)
   {
      uint j = 0;
      while (j < M && T[s + j] == P[j]) j++;
      return j >= M;
   };

   rabinKarp_preprocessing(P, T, M, h, ht, hp);

   for (uint i = 0; i <= N - M; ht = t_rehash(i), i++)
      if (ht == hp && check(i)) cnt++;
   
   return cnt;
}
