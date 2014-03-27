cppflags <- function(cmake=FALSE)
{
    inc.path <- tools::file_path_as_absolute(system.file("include", package="SEXPtools"))
    
    if (!cmake)
        flags <- paste("-I", inc.path, sep="")
    else
        flags <- inc.path

    cat(flags)
}

ldflags <- function(arch = '')
{
    file.path <- paste("lib/", arch, sep = "")

    ld.path <- tools::file_path_as_absolute(system.file(file.path, package="SEXPtools"))

    flags <- paste(ld.path, "/libsexptools.a", sep="")

    cat(flags)
}
