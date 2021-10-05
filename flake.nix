{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (
      system:
        let
          pkgs = import "${nixpkgs}" { system = system; config.allowUnfree = true; };
        in
          {
            devShell = pkgs.mkShell {
              name = "js-sh";
              nativeBuildInputs = [ pkgs.bashInteractive ];
              buildInputs = with pkgs; [ gcc make ];
              shellHook = ''
                export PATH="./node_modules/.bin:/home/plumps/.npm-packages/bin:$PATH"
              '';

              NPM_CONFIG_PREFIX = "/home/plumps/.npm-packages";

            };
          }
    );
}
