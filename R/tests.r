test_list <- function(names=TRUE) .Call("test_list", as.integer(names), PACKAGE="SEXPtools")

test_print <- function() .Call("test_print", PACKAGE="SEXPtools")

test_df <- function() .Call("test_df", PACKAGE="SEXPtools")

