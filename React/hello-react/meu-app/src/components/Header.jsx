/* File: src/components/Header.jsx */
import React from "react";

export default function Header() {
  return (
    <header className="bg-white shadow-sm">
      <div className="max-w-4xl mx-auto p-4 flex items-center justify-between">
        <div>
          <h1 className="text-2xl font-semibold">Posts Explorer</h1>
          <p className="text-sm text-slate-500">
            Exemplo didático — React + React Query + Tailwind. Busque e explore posts.
          </p>
        </div>
        <div className="text-sm text-slate-400">Demo</div>
      </div>
    </header>
  );
}
