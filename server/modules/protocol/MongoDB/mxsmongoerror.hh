// https://github.com/mongodb/mongo/blob/master/src/mongo/base/error_codes.yml

#if !defined(MXSMONGO_ERROR)
#error mxsmongoerror.hh cannot be included without MXSMONGO_ERROR being defined.
#endif

// The "location" errors are not documented, but appears to be created
// more or less on the spot in the Mongo code and used for fringe cases.

MXSMONGO_ERROR(OK,                         0, "OK")
MXSMONGO_ERROR(BAD_VALUE,                  2, "BadValue")
MXSMONGO_ERROR(FAILED_TO_PARSE,            9, "FailedToParse")
MXSMONGO_ERROR(COMMAND_NOT_FOUND,         59, "CommandNotFound")
MXSMONGO_ERROR(NO_REPLICATION_ENABLED,    76, "NoReplicationEnabled")
MXSMONGO_ERROR(COMMAND_FAILED,           125, "CommandFailed")
MXSMONGO_ERROR(LOCATION15974,          15974, "Location15974")
MXSMONGO_ERROR(LOCATION15975,          15975, "Location15975")
MXSMONGO_ERROR(LOCATION40352,          40352, "Location40352")