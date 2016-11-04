library(RNACI, quietly=TRUE)

CHECK <- function(test, truth) stopifnot(identical(test, truth))

### Dataframes
test <- RNACI_df()
truth <- data.frame(a=1:4, b=123456/(1:4))
CHECK(test, truth)

test <- RNACI_df_nonames()
colnames(truth) <- NULL
CHECK(test, truth)

test <- RNACI_df_empty()
truth <- data.frame()
CHECK(test, truth)


### Lists
