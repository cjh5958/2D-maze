#pragma once

#ifndef CORE_H
#define CORE_H

#ifndef _STR
#define _STR(x) #x
#define _XSTR(x) _STR(x)
#endif

#ifdef __GNUC__
#define likely(m_cond)   __builtin_expect(!!(m_cond),1)
#define unlikely(m_cond) __builtin_expect(!!(m_cond),0)
#else
#define likely(m_cond)   m_cond
#define unlikely(m_cond) m_cond
#endif


#ifdef NDEBUG
#undef STRICT_DEV_ENABLED
#else
#define STRICT_DEV_ENABLED
#endif

#endif
