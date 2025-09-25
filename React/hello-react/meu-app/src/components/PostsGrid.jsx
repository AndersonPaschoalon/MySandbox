/* File: src/components/PostsGrid.jsx */
import React, { useMemo, useState } from "react";
import { useQuery } from "@tanstack/react-query";
import { fetchPosts } from "../api/posts";
import useDebounce from "../hooks/useDebounce";
import PostCard from "./PostCard";

/* Why: central component showcasing fetching, caching, search+debounce, pagination, loading/error states */
export default function PostsGrid({ search }) {
  const { data, isLoading, isError, error, refetch, isFetching } = useQuery({
    queryKey: ["posts"],
    queryFn: fetchPosts,
    staleTime: 1000 * 60 * 5 // 5 minutes cache — padrão profissional
  });

  const debouncedSearch = useDebounce(search, 350);

  // filter client-side (JSONPlaceholder doesn't support search param)
  const filtered = useMemo(() => {
    if (!data) return [];
    const q = debouncedSearch.trim().toLowerCase();
    if (!q) return data;
    return data.filter(
      (p) =>
        p.title.toLowerCase().includes(q) || p.body.toLowerCase().includes(q)
    );
  }, [data, debouncedSearch]);

  // Pagination (client-side)
  const [page, setPage] = useState(1);
  const pageSize = 9;
  const total = filtered.length;
  const totalPages = Math.max(1, Math.ceil(total / pageSize));
  const pageItems = filtered.slice((page - 1) * pageSize, page * pageSize);

  // Reset to first page when search changes
  React.useEffect(() => setPage(1), [debouncedSearch]);

  return (
    <section>
      <div className="flex items-center justify-between mb-4">
        <div className="text-sm text-slate-600">
          {isLoading ? "Carregando posts..." : `${total} resultado(s)`}
          {isFetching && !isLoading ? " · atualizando..." : ""}
        </div>
        <div>
          <button
            className="text-xs text-brand-500 hover:underline"
            onClick={() => refetch()}
            aria-label="Recarregar posts"
          >
            Recarregar
          </button>
        </div>
      </div>

      {/* Loading skeleton */}
      {isLoading ? (
        <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-4">
          {Array.from({ length: 6 }).map((_, i) => (
            <div key={i} className="p-4 bg-white rounded-lg shadow-sm border border-slate-100">
              <div className="skeleton h-6 w-3/4 mb-3"></div>
              <div className="skeleton h-4 w-full mb-2"></div>
              <div className="skeleton h-4 w-full mb-2"></div>
            </div>
          ))}
        </div>
      ) : isError ? (
        <div className="p-6 bg-red-50 text-red-700 rounded">
          <div className="font-semibold">Erro ao carregar posts</div>
          <div className="mt-2">{String(error)}</div>
          <div className="mt-3">
            <button
              className="px-3 py-1 bg-red-600 text-white rounded"
              onClick={() => refetch()}
            >
              Tentar novamente
            </button>
          </div>
        </div>
      ) : pageItems.length === 0 ? (
        <div className="p-6 bg-yellow-50 text-yellow-700 rounded">
          Nenhum post encontrado para "<strong>{debouncedSearch}</strong>"
        </div>
      ) : (
        <>
          <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-4">
            {pageItems.map((post) => (
              <PostCard key={post.id} post={post} />
            ))}
          </div>

          {/* Pagination controls */}
          <div className="mt-6 flex items-center justify-between">
            <div className="text-sm text-slate-600">
              Página {page} de {totalPages}
            </div>
            <div className="flex gap-2">
              <button
                className="px-3 py-1 bg-white border rounded disabled:opacity-50"
                onClick={() => setPage((p) => Math.max(1, p - 1))}
                disabled={page === 1}
              >
                Anterior
              </button>
              <button
                className="px-3 py-1 bg-white border rounded disabled:opacity-50"
                onClick={() => setPage((p) => Math.min(totalPages, p + 1))}
                disabled={page === totalPages}
              >
                Próxima
              </button>
            </div>
          </div>
        </>
      )}
    </section>
  );
}

