/* File: src/components/PostCard.jsx */
import React from "react";

export default function PostCard({ post }) {
  return (
    <article className="p-4 bg-white rounded-lg shadow-sm border border-slate-100">
      <h3 className="font-semibold text-slate-800 mb-2">{post.title}</h3>
      <p className="text-sm text-slate-600 line-clamp-3">{post.body}</p>
      <div className="mt-3 text-xs text-slate-400">ID: {post.id}</div>
    </article>
  );
}

