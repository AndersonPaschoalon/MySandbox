/* File: src/hooks/useDebounce.js */
import { useEffect, useState } from "react";

/* Why: reduce rapid state updates (useful for search inputs) */
export default function useDebounce(value, delay = 400) {
  const [debounced, setDebounced] = useState(value);
  useEffect(() => {
    const t = setTimeout(() => setDebounced(value), delay);
    return () => clearTimeout(t);
  }, [value, delay]);
  return debounced;
}
