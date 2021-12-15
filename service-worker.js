filesToCache = [
    "/",
    "/side.wasm",
    "/side.js",
    "/index.html",
    "/index.css"
];
var cache_id = "side-cache-v1";

self.addEventListener('install', event => {
    console.log('Installing SIDE...');
  
    // cache necessary files
    event.waitUntil(
        caches.open(cache_id).then(function (cache) {
            cache.addAll(filesToCache);
        })
    );
});
  
self.addEventListener('activate', event => {
    console.log('SIDE is ready to handle fetches!');
});
  
self.addEventListener('fetch', event => {
    event.respondWith(caches.open(cache_id).then(function(cache) {
        cache.match(event.request).then(function(response){
            return response || fetch(event.request);
        })
    }));
});