/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <fnordmetric/http/httpinputstream.h>
#include <fnordmetric/http/httprequest.h>

namespace fnordmetric {
namespace http {

void HTTPRequest::readFromInputStream(HTTPInputStream* input) {
  input->readStatusLine(&method_, &url_, &version_);
  input->readHeaders(&headers_);

  const auto& content_length_header = getHeader("Content-Length");
  int content_length = 0;
  if (content_length_header.size() > 0) {
    try {
      content_length = std::stoi(content_length_header);
    } catch (std::exception e){
      /* invalid content length */
    }
  }

  if (content_length > 0) {
    input->getInputStream()->readNextBytes(&body_, content_length);
  }
}

const std::string& HTTPRequest::getMethod() const {
  return method_;
}

const std::string& HTTPRequest::getUrl() const {
  return url_;
}

const bool HTTPRequest::keepalive() const {
  if (getVersion() == "HTTP/1.1") {
    return true;
  }

  if (getHeader("Connection") == "keep-alive") {
    return true;
  }

  return false;
}

}
}