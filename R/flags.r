cppflags <- function(cmake=FALSE)
{
    inc.path <- tools::file_path_as_absolute(system.file("include", package="RNACI"))
    
    if(.Platform$OS.type != "windows"){
        if (!cmake)
            flags <- paste("-I", inc.path, sep="")
        else
            flags <- inc.path
    } else{
        flags <- paste("-I\"", inc.path, "\"", sep="")
    }

    cat(flags)
}

ldflags <- function(arch = '')
{
    if(.Platform$OS.type != "windows"){
      file.path <- paste("lib/", arch, sep = "")

      ld.path <- tools::file_path_as_absolute(system.file(file.path, package="RNACI"))

      flags <- paste(ld.path, "/librnaci.a", sep="")
    } else{
      file.path <- paste("lib/", .Platform$r_arch, sep = "")

      ld.path <- tools::file_path_as_absolute(system.file(file.path, package="RNACI"))

      flags <- paste("\"", ld.path, "/librnaci.a", "\"", sep="")
    }

    cat(flags)
}
