test_list <- function(names=TRUE) .Call("test_list", as.integer(names), PACKAGE="RNACI")

test_print <- function() .Call("test_print", PACKAGE="RNACI")

test_df <- function() .Call("test_df", PACKAGE="RNACI")

