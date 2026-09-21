// site_src.js — static syntax highlighting for C++ code blocks.
// Dependency-free; copied verbatim into website/site/site.js by build_site.py.
// Colorizes <pre><code> blocks that contain C++ statement punctuation.
(function () {
  "use strict";

  // Token classes, in priority order (capture groups 1-5):
  //   1 comments   2 strings/chars   3 preprocessor   4 numbers   5 keywords
  var RE = new RegExp([
    "(\\/\\*[\\s\\S]*?\\*\\/|\\/\\/[^\\r\\n]*)",
    "(\"(?:[^\"\\\\\\r\\n]|\\\\.)*\"|'(?:[^'\\\\\\r\\n]|\\\\.)*')",
    "(#[A-Za-z_]+|<[^>\\r\\n]+>)",
    "\\b(\\d[\\w.']*)\\b",
    "\\b(alignas|alignof|and|asm|auto|bool|break|case|catch|char|class|const|" +
      "constexpr|const_cast|continue|decltype|default|delete|do|double|" +
      "dynamic_cast|else|enum|explicit|extern|false|float|for|friend|goto|if|" +
      "inline|int|long|mutable|namespace|new|noexcept|not|nullptr|operator|or|" +
      "private|protected|public|reinterpret_cast|return|short|signed|sizeof|" +
      "static|static_assert|static_cast|struct|switch|template|this|throw|" +
      "true|try|typedef|typeid|typename|union|unsigned|using|virtual|void|" +
      "volatile|wchar_t|while|xor|std|string|vector|size_t|ifstream|ofstream|" +
      "fstream)\\b"
  ].join("|"), "g");

  function esc(s) {
    return s.replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;");
  }

  // Only colorize blocks with statement punctuation (skips prose-in-code).
  var CODE_HINT = /[;{}]/;

  document.querySelectorAll("pre > code").forEach(function (el) {
    var src = el.textContent;
    if (!CODE_HINT.test(src)) return;
    var out = "", last = 0, m;
    RE.lastIndex = 0;
    while ((m = RE.exec(src)) !== null) {
      out += esc(src.slice(last, m.index));
      var cls = m[1] ? "tok-c" : m[2] ? "tok-s" : m[3] ? "tok-p" : m[4] ? "tok-n" : "tok-k";
      out += '<span class="' + cls + '">' + esc(m[0]) + "</span>";
      last = m.index + m[0].length;
      if (m[0].length === 0) RE.lastIndex++;
    }
    out += esc(src.slice(last));
    el.innerHTML = out;
  });
})();
