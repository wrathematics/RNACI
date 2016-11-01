library(RNACI, quietly=TRUE)


### Lists
a <- list(abc=1:2, defg=-10.10214)
b <- RNACI:::test_list(TRUE)
all.equal(a, b)

names(a) <- NULL
b <- RNACI:::test_list(FALSE)
all.equal(a, b)


### Dataframes
a <- data.frame(X1=1:4, X2=123456/(1:4))
b <- RNACI:::test_df()
all.equal(a, b)


### Printing
RNACI:::test_print()
