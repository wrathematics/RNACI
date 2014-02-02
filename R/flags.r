cppflags <- function()
{
    inc.path <- tools::file_path_as_absolute(system.file("include", package="SEXPtools"))
    
    flags <- paste("-I", inc.path, sep="")

    cat(flags)
}

ldflags <- function()
{
    ld.path <- tools::file_path_as_absolute(system.file("lib", package="SEXPtools"))

    flags <- paste(ld.path, "/libsexptools.a", sep="")

    cat(flags)
}
