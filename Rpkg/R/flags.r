#' cppflags
#' 
#' The CPPFLAGS for use when linking agains RNACI.
#' 
#' @param cmake
#' For use with CMake or not.
#' 
#' @export
cppflags <- function(cmake=FALSE)
{
  inc.path <- tools::file_path_as_absolute(system.file("include", package="RNACI"))
  
  if(.Platform$OS.type != "windows")
  {
    if (!cmake)
      flags <- paste("-I", inc.path, sep="")
    else
      flags <- inc.path
  } 
  else
    flags <- paste("-I\"", inc.path, "\"", sep="")
  
  cat(flags)
}



#' ldflags
#' 
#' The LDFLAGS for use when linking agains RNACI.
#' 
#' @param arch
#' Optional arch value.
#' 
#' @export
ldflags <- function(arch='')
{
  if(.Platform$OS.type != "windows")
  {
    file.path <- paste("lib/", arch, sep = "")
    
    ld.path <- tools::file_path_as_absolute(system.file(file.path, package="RNACI"))
    
    flags <- paste(ld.path, "/librnaci.a", sep="")
  }
  else
  {
    file.path <- paste("lib/", .Platform$r_arch, sep = "")
    
    ld.path <- tools::file_path_as_absolute(system.file(file.path, package="RNACI"))
    
    flags <- paste("\"", ld.path, "/librnaci.a", "\"", sep="")
  }
  
  cat(flags)
}
