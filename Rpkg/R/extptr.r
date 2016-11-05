#' @export
RNACI_createptr <- function() .Call("RNACI_createptr")

#' @export
RNACI_getptr <- function(Rptr) invisible(.Call("RNACI_getptr", Rptr))
