FROM paperist/alpine-texlive-ja

WORKDIR /usr/local/texlive/2019/texmf-dist/tex/latex/listing
RUN apk add curl && \
    curl -OL http://sourceforge.jp/projects/mytexpert/downloads/26068/jlisting.sty.bz2 && \
    bzip2 -d jlisting.sty.bz2 && \
    mktexlsr

WORKDIR /workdir
CMD ["sh"]
