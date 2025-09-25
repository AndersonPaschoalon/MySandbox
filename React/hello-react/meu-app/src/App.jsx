/* File: src/App.jsx */
import React, { useState } from "react";
import Header from "./components/Header";
import SearchBar from "./components/SearchBar";
import PostsGrid from "./components/PostsGrid";
import Footer from "./components/Footer";


export default function App() {
  const [query, setQuery] = useState(""); // search term (top-level state)
  console.log("[App render] query =", query);
  return (
    <div className="min-h-screen bg-slate-50 text-slate-900">
      <Header />
      <main className="flex-grow max-w-4xl mx-auto p-4">
        <SearchBar value={query} onChange={setQuery} />
        <PostsGrid search={query} />
      </main>
      <Footer/>
    </div>
  );
}
