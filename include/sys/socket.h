#ifndef _FORTIFY_SYS_SOCKET_H
#define _FORTIFY_SYS_SOCKET_H

#include_next <sys/socket.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifndef __cplusplus

static inline __attribute__ ((always_inline))
ssize_t
__fortify_recv(int sockfd, void *buf, size_t n, int flags)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return recv(sockfd, buf, n, flags);
}

static inline __attribute__ ((always_inline))
ssize_t
__fortify_recvfrom(int sockfd, void *buf, size_t n, int flags,
                   struct sockaddr *sa, socklen_t *salen)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return recvfrom(sockfd, buf, n, flags, sa, salen);
}

static inline __attribute__ ((always_inline))
ssize_t
__fortify_send(int sockfd, const void *buf, size_t n, int flags)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return send(sockfd, buf, n, flags);
}

static inline __attribute__ ((always_inline))
ssize_t
__fortify_sendto(int sockfd, const void *buf, size_t n, int flags,
                 const struct sockaddr *sa, socklen_t salen)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return sendto(sockfd, buf, n, flags, sa, salen);
}

#undef recv
#define recv(sockfd, buf, n, flags) __fortify_recv(sockfd, buf, n, flags)
#undef recvfrom
#define recvfrom(sockfd, buf, n, flags, sa, salen) __fortify_recvfrom(sockfd, buf, n, flags, sa, salen)
#undef send
#define send(sockfd, buf, n, flags) __fortify_send(sockfd, buf, n, flags)
#undef sendto
#define sendto(sockfd, buf, n, flags, sa, salen) __fortify_sendto(sockfd, buf, n, flags, sa, salen)

#endif

#endif

#endif
