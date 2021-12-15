filesToCache = [
    "/side.wasm",
    "/side.js",
    "index.html",
    "index.css"
]

self.addEventListener('install', event => {
    console.log('Installing SIDE...');
  
    // cache necessary files
    event.waitUntil(
        caches.open('side-cache').then(function (cache) {
            for(var file in filesToCache) {
                cache.add(file);
            }
        })
    );
});
  
self.addEventListener('activate', event => {
    console.log('SIDE is ready to handle fetches!');
});
  
self.addEventListener('fetch', event => {
    const url = new URL(event.request.url);
  
    // Serve all cached content
    if (url.origin == location.origin && url.pathname == '/') {
        for(var file in filesToCache) {
            event.respondWith(caches.match(file));
        }
    }
});