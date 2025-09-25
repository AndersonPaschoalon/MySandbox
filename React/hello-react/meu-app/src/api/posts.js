/* File: src/api/posts.js */
import axios from "axios";

const API_BASE = "https://jsonplaceholder.typicode.com";

/* Why: keep HTTP logic isolated for reuse and easier testing. */
export async function fetchPosts() {
  const res = await axios.get(`${API_BASE}/posts`);
  return res.data; // array of posts
}
