/* File: src/components/SearchBar.jsx */
import React from "react";

export default function SearchBar({ value, onChange }) {
  console.log("[SearchBar render] value recebido =", value);
  return (
    <div className="my-6">
      <label htmlFor="search" className="sr-only">Pesquisar posts</label>
      <div className="relative">
        <input
          id="search"
          type="search"
          value={value}
          onChange={(e) => onChange(e.target.value)}
          placeholder="Pesquisar por título ou conteúdo..."
          className="w-full rounded-lg border border-slate-200 px-4 py-3 shadow-sm focus:outline-none focus:ring-2 focus:ring-brand-500"
          aria-label="Pesquisar posts"
        />
        <span className="absolute right-3 top-3 text-slate-400">🔎</span>
      </div>
    </div>
  );
}
