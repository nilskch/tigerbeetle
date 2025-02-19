 //////////////////////////////////////////////////////////
 // This file was auto-generated by tb_client_header.zig //
 //              Do not manually modify.                 //
 //////////////////////////////////////////////////////////

#ifndef TB_CLIENT_H
#define TB_CLIENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef __uint128_t tb_uint128_t;

typedef enum TB_ACCOUNT_FLAGS {
    TB_ACCOUNT_LINKED = 1 << 0,
    TB_ACCOUNT_DEBITS_MUST_NOT_EXCEED_CREDITS = 1 << 1,
    TB_ACCOUNT_CREDITS_MUST_NOT_EXCEED_DEBITS = 1 << 2,
    TB_ACCOUNT_HISTORY = 1 << 3,
    TB_ACCOUNT_IMPORTED = 1 << 4,
    TB_ACCOUNT_CLOSED = 1 << 5,
} TB_ACCOUNT_FLAGS;

typedef struct tb_account_t {
    tb_uint128_t id;
    tb_uint128_t debits_pending;
    tb_uint128_t debits_posted;
    tb_uint128_t credits_pending;
    tb_uint128_t credits_posted;
    tb_uint128_t user_data_128;
    uint64_t user_data_64;
    uint32_t user_data_32;
    uint32_t reserved;
    uint32_t ledger;
    uint16_t code;
    uint16_t flags;
    uint64_t timestamp;
} tb_account_t;

typedef enum TB_TRANSFER_FLAGS {
    TB_TRANSFER_LINKED = 1 << 0,
    TB_TRANSFER_PENDING = 1 << 1,
    TB_TRANSFER_POST_PENDING_TRANSFER = 1 << 2,
    TB_TRANSFER_VOID_PENDING_TRANSFER = 1 << 3,
    TB_TRANSFER_BALANCING_DEBIT = 1 << 4,
    TB_TRANSFER_BALANCING_CREDIT = 1 << 5,
    TB_TRANSFER_CLOSING_DEBIT = 1 << 6,
    TB_TRANSFER_CLOSING_CREDIT = 1 << 7,
    TB_TRANSFER_IMPORTED = 1 << 8,
} TB_TRANSFER_FLAGS;

typedef struct tb_transfer_t {
    tb_uint128_t id;
    tb_uint128_t debit_account_id;
    tb_uint128_t credit_account_id;
    tb_uint128_t amount;
    tb_uint128_t pending_id;
    tb_uint128_t user_data_128;
    uint64_t user_data_64;
    uint32_t user_data_32;
    uint32_t timeout;
    uint32_t ledger;
    uint16_t code;
    uint16_t flags;
    uint64_t timestamp;
} tb_transfer_t;

typedef enum TB_CREATE_ACCOUNT_RESULT {
    TB_CREATE_ACCOUNT_OK = 0,
    TB_CREATE_ACCOUNT_LINKED_EVENT_FAILED = 1,
    TB_CREATE_ACCOUNT_LINKED_EVENT_CHAIN_OPEN = 2,
    TB_CREATE_ACCOUNT_IMPORTED_EVENT_EXPECTED = 22,
    TB_CREATE_ACCOUNT_IMPORTED_EVENT_NOT_EXPECTED = 23,
    TB_CREATE_ACCOUNT_TIMESTAMP_MUST_BE_ZERO = 3,
    TB_CREATE_ACCOUNT_IMPORTED_EVENT_TIMESTAMP_OUT_OF_RANGE = 24,
    TB_CREATE_ACCOUNT_IMPORTED_EVENT_TIMESTAMP_MUST_NOT_ADVANCE = 25,
    TB_CREATE_ACCOUNT_RESERVED_FIELD = 4,
    TB_CREATE_ACCOUNT_RESERVED_FLAG = 5,
    TB_CREATE_ACCOUNT_ID_MUST_NOT_BE_ZERO = 6,
    TB_CREATE_ACCOUNT_ID_MUST_NOT_BE_INT_MAX = 7,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_FLAGS = 15,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_USER_DATA_128 = 16,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_USER_DATA_64 = 17,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_USER_DATA_32 = 18,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_LEDGER = 19,
    TB_CREATE_ACCOUNT_EXISTS_WITH_DIFFERENT_CODE = 20,
    TB_CREATE_ACCOUNT_EXISTS = 21,
    TB_CREATE_ACCOUNT_FLAGS_ARE_MUTUALLY_EXCLUSIVE = 8,
    TB_CREATE_ACCOUNT_DEBITS_PENDING_MUST_BE_ZERO = 9,
    TB_CREATE_ACCOUNT_DEBITS_POSTED_MUST_BE_ZERO = 10,
    TB_CREATE_ACCOUNT_CREDITS_PENDING_MUST_BE_ZERO = 11,
    TB_CREATE_ACCOUNT_CREDITS_POSTED_MUST_BE_ZERO = 12,
    TB_CREATE_ACCOUNT_LEDGER_MUST_NOT_BE_ZERO = 13,
    TB_CREATE_ACCOUNT_CODE_MUST_NOT_BE_ZERO = 14,
    TB_CREATE_ACCOUNT_IMPORTED_EVENT_TIMESTAMP_MUST_NOT_REGRESS = 26,
} TB_CREATE_ACCOUNT_RESULT;

typedef enum TB_CREATE_TRANSFER_RESULT {
    TB_CREATE_TRANSFER_OK = 0,
    TB_CREATE_TRANSFER_LINKED_EVENT_FAILED = 1,
    TB_CREATE_TRANSFER_LINKED_EVENT_CHAIN_OPEN = 2,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_EXPECTED = 56,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_NOT_EXPECTED = 57,
    TB_CREATE_TRANSFER_TIMESTAMP_MUST_BE_ZERO = 3,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_TIMESTAMP_OUT_OF_RANGE = 58,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_TIMESTAMP_MUST_NOT_ADVANCE = 59,
    TB_CREATE_TRANSFER_RESERVED_FLAG = 4,
    TB_CREATE_TRANSFER_ID_MUST_NOT_BE_ZERO = 5,
    TB_CREATE_TRANSFER_ID_MUST_NOT_BE_INT_MAX = 6,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_FLAGS = 36,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_PENDING_ID = 40,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_TIMEOUT = 44,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_DEBIT_ACCOUNT_ID = 37,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_CREDIT_ACCOUNT_ID = 38,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_AMOUNT = 39,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_USER_DATA_128 = 41,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_USER_DATA_64 = 42,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_USER_DATA_32 = 43,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_LEDGER = 67,
    TB_CREATE_TRANSFER_EXISTS_WITH_DIFFERENT_CODE = 45,
    TB_CREATE_TRANSFER_EXISTS = 46,
    TB_CREATE_TRANSFER_ID_ALREADY_FAILED = 68,
    TB_CREATE_TRANSFER_FLAGS_ARE_MUTUALLY_EXCLUSIVE = 7,
    TB_CREATE_TRANSFER_DEBIT_ACCOUNT_ID_MUST_NOT_BE_ZERO = 8,
    TB_CREATE_TRANSFER_DEBIT_ACCOUNT_ID_MUST_NOT_BE_INT_MAX = 9,
    TB_CREATE_TRANSFER_CREDIT_ACCOUNT_ID_MUST_NOT_BE_ZERO = 10,
    TB_CREATE_TRANSFER_CREDIT_ACCOUNT_ID_MUST_NOT_BE_INT_MAX = 11,
    TB_CREATE_TRANSFER_ACCOUNTS_MUST_BE_DIFFERENT = 12,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_BE_ZERO = 13,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_NOT_BE_ZERO = 14,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_NOT_BE_INT_MAX = 15,
    TB_CREATE_TRANSFER_PENDING_ID_MUST_BE_DIFFERENT = 16,
    TB_CREATE_TRANSFER_TIMEOUT_RESERVED_FOR_PENDING_TRANSFER = 17,
    TB_CREATE_TRANSFER_CLOSING_TRANSFER_MUST_BE_PENDING = 64,
    TB_CREATE_TRANSFER_AMOUNT_MUST_NOT_BE_ZERO = 18,
    TB_CREATE_TRANSFER_LEDGER_MUST_NOT_BE_ZERO = 19,
    TB_CREATE_TRANSFER_CODE_MUST_NOT_BE_ZERO = 20,
    TB_CREATE_TRANSFER_DEBIT_ACCOUNT_NOT_FOUND = 21,
    TB_CREATE_TRANSFER_CREDIT_ACCOUNT_NOT_FOUND = 22,
    TB_CREATE_TRANSFER_ACCOUNTS_MUST_HAVE_THE_SAME_LEDGER = 23,
    TB_CREATE_TRANSFER_TRANSFER_MUST_HAVE_THE_SAME_LEDGER_AS_ACCOUNTS = 24,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_NOT_FOUND = 25,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_NOT_PENDING = 26,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_DEBIT_ACCOUNT_ID = 27,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_CREDIT_ACCOUNT_ID = 28,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_LEDGER = 29,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_CODE = 30,
    TB_CREATE_TRANSFER_EXCEEDS_PENDING_TRANSFER_AMOUNT = 31,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_HAS_DIFFERENT_AMOUNT = 32,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_ALREADY_POSTED = 33,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_ALREADY_VOIDED = 34,
    TB_CREATE_TRANSFER_PENDING_TRANSFER_EXPIRED = 35,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_TIMESTAMP_MUST_NOT_REGRESS = 60,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_TIMESTAMP_MUST_POSTDATE_DEBIT_ACCOUNT = 61,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_TIMESTAMP_MUST_POSTDATE_CREDIT_ACCOUNT = 62,
    TB_CREATE_TRANSFER_IMPORTED_EVENT_TIMEOUT_MUST_BE_ZERO = 63,
    TB_CREATE_TRANSFER_DEBIT_ACCOUNT_ALREADY_CLOSED = 65,
    TB_CREATE_TRANSFER_CREDIT_ACCOUNT_ALREADY_CLOSED = 66,
    TB_CREATE_TRANSFER_OVERFLOWS_DEBITS_PENDING = 47,
    TB_CREATE_TRANSFER_OVERFLOWS_CREDITS_PENDING = 48,
    TB_CREATE_TRANSFER_OVERFLOWS_DEBITS_POSTED = 49,
    TB_CREATE_TRANSFER_OVERFLOWS_CREDITS_POSTED = 50,
    TB_CREATE_TRANSFER_OVERFLOWS_DEBITS = 51,
    TB_CREATE_TRANSFER_OVERFLOWS_CREDITS = 52,
    TB_CREATE_TRANSFER_OVERFLOWS_TIMEOUT = 53,
    TB_CREATE_TRANSFER_EXCEEDS_CREDITS = 54,
    TB_CREATE_TRANSFER_EXCEEDS_DEBITS = 55,
} TB_CREATE_TRANSFER_RESULT;

typedef struct tb_create_accounts_result_t {
    uint32_t index;
    uint32_t result;
} tb_create_accounts_result_t;

typedef struct tb_create_transfers_result_t {
    uint32_t index;
    uint32_t result;
} tb_create_transfers_result_t;

typedef struct tb_account_filter_t {
    tb_uint128_t account_id;
    tb_uint128_t user_data_128;
    uint64_t user_data_64;
    uint32_t user_data_32;
    uint16_t code;
    uint8_t reserved[58];
    uint64_t timestamp_min;
    uint64_t timestamp_max;
    uint32_t limit;
    uint32_t flags;
} tb_account_filter_t;

typedef enum TB_ACCOUNT_FILTER_FLAGS {
    TB_ACCOUNT_FILTER_DEBITS = 1 << 0,
    TB_ACCOUNT_FILTER_CREDITS = 1 << 1,
    TB_ACCOUNT_FILTER_REVERSED = 1 << 2,
} TB_ACCOUNT_FILTER_FLAGS;

typedef struct tb_account_balance_t {
    tb_uint128_t debits_pending;
    tb_uint128_t debits_posted;
    tb_uint128_t credits_pending;
    tb_uint128_t credits_posted;
    uint64_t timestamp;
    uint8_t reserved[56];
} tb_account_balance_t;

typedef struct tb_query_filter_t {
    tb_uint128_t user_data_128;
    uint64_t user_data_64;
    uint32_t user_data_32;
    uint32_t ledger;
    uint16_t code;
    uint8_t reserved[6];
    uint64_t timestamp_min;
    uint64_t timestamp_max;
    uint32_t limit;
    uint32_t flags;
} tb_query_filter_t;

typedef enum TB_QUERY_FILTER_FLAGS {
    TB_QUERY_FILTER_REVERSED = 1 << 0,
} TB_QUERY_FILTER_FLAGS;

// Opaque struct serving as a handle for the client instance.
// This struct must be "pinned" (not copyable or movable), as its address must remain stable
// throughout the lifetime of the client instance.
typedef struct tb_client_t {
    uint64_t opaque[4];
} tb_client_t;

// Struct containing the state of a request submitted through the client.
// This struct must be "pinned" (not copyable or movable), as its address must remain stable
// throughout the lifetime of the request.
typedef struct tb_packet_t {
    void* user_data;
    void* data;
    uint32_t data_size;
    uint16_t user_tag;
    uint8_t operation;
    uint8_t status;
    uint8_t opaque[32];
} tb_packet_t;

typedef enum TB_OPERATION {
    TB_OPERATION_PULSE = 128,
    TB_OPERATION_CREATE_ACCOUNTS = 129,
    TB_OPERATION_CREATE_TRANSFERS = 130,
    TB_OPERATION_LOOKUP_ACCOUNTS = 131,
    TB_OPERATION_LOOKUP_TRANSFERS = 132,
    TB_OPERATION_GET_ACCOUNT_TRANSFERS = 133,
    TB_OPERATION_GET_ACCOUNT_BALANCES = 134,
    TB_OPERATION_QUERY_ACCOUNTS = 135,
    TB_OPERATION_QUERY_TRANSFERS = 136,
    TB_OPERATION_GET_EVENTS = 137,
} TB_OPERATION;

typedef enum TB_PACKET_STATUS {
    TB_PACKET_OK = 0,
    TB_PACKET_TOO_MUCH_DATA = 1,
    TB_PACKET_CLIENT_EVICTED = 2,
    TB_PACKET_CLIENT_RELEASE_TOO_LOW = 3,
    TB_PACKET_CLIENT_RELEASE_TOO_HIGH = 4,
    TB_PACKET_CLIENT_SHUTDOWN = 5,
    TB_PACKET_INVALID_OPERATION = 6,
    TB_PACKET_INVALID_DATA_SIZE = 7,
} TB_PACKET_STATUS;

typedef enum TB_INIT_STATUS {
    TB_INIT_SUCCESS = 0,
    TB_INIT_UNEXPECTED = 1,
    TB_INIT_OUT_OF_MEMORY = 2,
    TB_INIT_ADDRESS_INVALID = 3,
    TB_INIT_ADDRESS_LIMIT_EXCEEDED = 4,
    TB_INIT_SYSTEM_RESOURCES = 5,
    TB_INIT_NETWORK_SUBSYSTEM = 6,
} TB_INIT_STATUS;

typedef enum TB_CLIENT_STATUS {
    TB_CLIENT_OK = 0,
    TB_CLIENT_INVALID = 1,
} TB_CLIENT_STATUS;

typedef enum TB_REGISTER_LOG_CALLBACK_STATUS {
    TB_REGISTER_LOG_CALLBACK_SUCCESS = 0,
    TB_REGISTER_LOG_CALLBACK_ALREADY_REGISTERED = 1,
    TB_REGISTER_LOG_CALLBACK_NOT_REGISTERED = 2,
} TB_REGISTER_LOG_CALLBACK_STATUS;

typedef enum TB_LOG_LEVEL {
    TB_LOG_ERR = 0,
    TB_LOG_WARN = 1,
    TB_LOG_INFO = 2,
    TB_LOG_DEBUG = 3,
} TB_LOG_LEVEL;

// Initialize a new TigerBeetle client which connects to the addresses provided and
// completes submitted packets by invoking the callback with the given context.
TB_INIT_STATUS tb_client_init(
    tb_client_t *client_out,
    // 128-bit unsigned integer represented as a 16-byte little-endian array.
    const uint8_t cluster_id[16],
    const char *address_ptr,
    uint32_t address_len,
    uintptr_t completion_ctx,
    void (*completion_callback)(uintptr_t, tb_packet_t*, uint64_t, const uint8_t*, uint32_t)
);

// Initialize a new TigerBeetle client that echoes back any submitted data.
TB_INIT_STATUS tb_client_init_echo(
    tb_client_t *client_out,
    // 128-bit unsigned integer represented as a 16-byte little-endian array.
    const uint8_t cluster_id[16],
    const char *address_ptr,
    uint32_t address_len,
    uintptr_t completion_ctx,
    void (*completion_callback)(uintptr_t, tb_packet_t*, uint64_t, const uint8_t*, uint32_t)
);

// Retrieve the callback context initially passed to `tb_client_init` or `tb_client_init_echo`.
// Return value: `TB_CLIENT_OK` on success, or `TB_CLIENT_INVALID` if the client handle was
// not initialized or has already been closed.
TB_CLIENT_STATUS tb_client_completion_context(
    tb_client_t* client,
    uintptr_t* completion_ctx_out
);

// Submit a packet with its `operation`, `data`, and `data_size` fields set.
// Once completed, `completion_callback` will be invoked with `completion_ctx`
// and the given packet on the `tb_client` thread (separate from the caller's thread).
// Return value: `TB_CLIENT_OK` on success, or `TB_CLIENT_INVALID` if the client handle was
// not initialized or has already been closed.
TB_CLIENT_STATUS tb_client_submit(
    tb_client_t *client,
    tb_packet_t *packet
);

// Closes the client, causing any previously submitted packets to be completed with
// `TB_PACKET_CLIENT_SHUTDOWN` before freeing any allocated client resources from init.
// Return value: `TB_CLIENT_OK` on success, or `TB_CLIENT_INVALID` if the client handle was
// not initialized or has already been closed.
TB_CLIENT_STATUS tb_client_deinit(
    tb_client_t *client
);

// Registers or unregisters the application log callback.
TB_REGISTER_LOG_CALLBACK_STATUS register_log_callback(
    void (*callback)(TB_LOG_LEVEL, const uint8_t*, uint32_t),
    bool debug
);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TB_CLIENT_H
